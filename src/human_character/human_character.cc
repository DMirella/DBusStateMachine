#include "human_character.h"

#include <iostream>

#include "animation_screen.h"

namespace DBusStateMachine {
HumanCharacter::HumanCharacter() : screen_(nullptr){
  screen_ = AnimationScreen::GetInstance();
  Init();
}

bool HumanCharacter::Init() {
  const int animation_area_width = 20, animation_area_height = 20;
  const int animation_body_x = 5, animation_body_y = 5;
  const int animation_head_x = animation_body_x - HeadHumanCharacterSnaps::kWidth / 2, 
            animation_head_y = animation_body_y - HeadHumanCharacterSnaps::kHeight;
  const int animation_left_arm_x = animation_body_x - ArmHumanCharacterSnaps::kWidth,
            animation_left_arm_y = animation_body_y - 1;
  const int animation_right_arm_x = animation_body_x + BodyHumanCharacterSnaps::kWidth,
            animation_right_arm_y = animation_body_y - 1;
  const int animation_left_leg_x = animation_body_x - ArmHumanCharacterSnaps::kWidth + 1,
            animation_left_leg_y = animation_body_y + ArmHumanCharacterSnaps::kHeight;
  const int animation_right_leg_x = animation_body_x + BodyHumanCharacterSnaps::kWidth,
            animation_right_leg_y = animation_body_y + BodyHumanCharacterSnaps::kHeight;
  
  animation_area_ = std::make_shared<AnimationArea>(0, 0, animation_area_width, animation_area_height);
  animation_head_ = std::make_shared<HeadHumanCharacterAnimation>(animation_head_x, animation_head_y);
  animation_body_ = std::make_shared<BodyHumanCharacterAnimation>(animation_body_x, animation_body_y);
  animation_left_arm_ = std::make_shared<ArmHumanCharacterAnimation>(animation_left_arm_x, 
								     animation_left_arm_y,
								     Arm::LEFT);
  animation_right_arm_ = std::make_shared<ArmHumanCharacterAnimation>(animation_right_arm_x, 
								      animation_right_arm_y,
								      Arm::RIGHT);
  animation_left_leg_ = std::make_shared<LegHumanCharacterAnimation>(animation_left_leg_x, animation_left_leg_y);
  animation_right_leg_ = std::make_shared<LegHumanCharacterAnimation>(animation_right_leg_x, animation_right_leg_y);

  animation_area_->AddAnimation(animation_head_);
  animation_area_->AddAnimation(animation_body_);
  animation_area_->AddAnimation(animation_left_arm_);
  animation_area_->AddAnimation(animation_right_arm_);
  animation_area_->AddAnimation(animation_left_leg_);
  animation_area_->AddAnimation(animation_right_leg_);
  screen_->set_main_animation(animation_area_);
}

void HumanCharacter::ArmUp(Arm arm) {
  if (arm == Arm::LEFT) {
    animation_left_arm_->PlayUpArmAnimation();
  } else { 
    animation_right_arm_->PlayUpArmAnimation();
  }
}

void HumanCharacter::ArmDown(Arm arm) {
  if (arm == Arm::LEFT) {
    animation_left_arm_->PlayDownArmAnimation();
  } else { 
    animation_right_arm_->PlayDownArmAnimation();
  }
  
}
}  // DBusStateMachine
