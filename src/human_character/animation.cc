#include "animation.h"

#include <iostream>

namespace DBusStateMachine {
void AnimationArea::AddAnimation(const std::shared_ptr<Animation>& animation) {
  if (animation == nullptr) {
    std::cerr << "Error in AnimationArea::AddAnimation(...): animation == nullptr\n";
    return;
  }
  animations_.emplace_back(animation);
}

Snap AnimationArea::MakeSnap() const {
  PixelMap result_image(height_, std::vector<Pixel>(width_, kEmptyPixel));
  for (const auto& animation : animations_) {
    int animation_width = animation->width();
    int animation_height = animation->height();
    Snap animation_sprite = animation->MakeSnap();
    auto animation_image = animation_sprite.image();
    int animation_x = animation->x();
    int animation_y = animation->y();
    for (int shift_y = 0; shift_y < animation_height; ++shift_y) {
      for (int shift_x = 0; shift_x < animation_width; ++shift_x) {
	auto &current_result_image_pixel = result_image[animation_y + shift_y][animation_x + shift_x];
	if (animation_image[shift_y][shift_x] != kEmptyPixel) {
          current_result_image_pixel = animation_image[shift_y][shift_x];
	}
      }
    }
  }
  return Snap(result_image);
}
}  // DBusStateMachine
