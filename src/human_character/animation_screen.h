#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_SCREEN_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_SCREEN_H_

#include <atomic>
#include <memory>
#include <thread>
#include <vector>

#include "animation.h"

namespace DBusStateMachine {
class Animation;

class AnimationScreen {
 public:
  AnimationScreen(const AnimationScreen& service) = delete;
  AnimationScreen(AnimationScreen&& service) = delete;
  AnimationScreen& operator=(const AnimationScreen& service) = delete;
  AnimationScreen& operator=(AnimationScreen&& service) = delete;
  
  static AnimationScreen* GetInstance();
  
  void set_main_animation(const std::shared_ptr<Animation>& animation);
 private:
  AnimationScreen();
  ~AnimationScreen();
  
  void StartScreenThread();
  void PrintSnap(const Snap& snap) const;

  std::atomic<bool> is_need_to_destroy_screen_thread_;
  std::thread screen_thread_;
  std::shared_ptr<Animation> main_animation_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_SCREEN_H_
