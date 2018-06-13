#include "animation_screen.h"

#include <chrono>
#include <iostream>

namespace DBusStateMachine {
namespace {
const auto kPauseScreenThreadTimeMs = std::chrono::milliseconds(50);
}  // namespace

AnimationScreen::AnimationScreen()
    : is_need_to_destroy_screen_thread_(false), main_animation_(nullptr) {
  StartScreenThread();
}

AnimationScreen::~AnimationScreen() {
  is_need_to_destroy_screen_thread_ = true;
  screen_thread_.join();
}

AnimationScreen& AnimationScreen::GetInstance() {
  static AnimationScreen screen;
  return screen;
}

void AnimationScreen::set_main_animation(const std::shared_ptr<Animation>& animation) {
  if (animation == nullptr) {
    std::cerr << "Error in AnimationScreen::set_main_animation(...): animation == nullptr\n";
    return;
  }
  main_animation_ = animation;
}

void AnimationScreen::StartScreenThread() {
  is_need_to_destroy_screen_thread_ = false;
  screen_thread_ = std::thread([this]() {
                                 while (!is_need_to_destroy_screen_thread_) {
			     	   system("clear");
			     	   if (main_animation_ != nullptr) {
                               	     PrintSnap(main_animation_->MakeSnap());
			     	   } else {
			             std::cout << "No animation to view(Try to set the main animation).\n";
			     	   }
                             	   std::this_thread::sleep_for(kPauseScreenThreadTimeMs);
                                 } 
                               });
}

void AnimationScreen::PrintSnap(const Snap& snap) const {
  std::vector<std::vector<Pixel>> image = snap.image();
  for (auto pixels : image) {
    for(auto pixel : pixels) {
      std::cout << pixel.ToChar();
    }
    std::cout << '\n';
  }
}
}  // DBusStateMachine
