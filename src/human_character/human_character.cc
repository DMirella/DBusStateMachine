#include "human_character.h"

#include <iostream>

#include "animation_screen.h"

namespace DBusStateMachine {
HumanCharacter::HumanCharacter() 
    : screen_(nullptr), is_human_character_ready_(false) {
  screen_ = AnimationScreen::GetInstance();
  if (!(is_human_character_ready_ = Init())) {
    std::cerr << "Error in HumanCharacter::HumanCharacter(): Initialization failed.\n";
  }
}

bool HumanCharacter::Init() {
  const int kAnimationAreaWidth = 20, kAnimationAreaHeight = 20;
  const int kAnimationBodyX = 5, kAnimationBodyY = 5;
  const int kAnimationHeadX = kAnimationBodyX - HeadHumanCharacterSnaps::kWidth / 2, 
            kAnimationHeadY = kAnimationBodyY - HeadHumanCharacterSnaps::kHeight;
  const int kAnimationLeftArmX = kAnimationBodyX - ArmHumanCharacterSnaps::kWidth,
            kAnimationLeftArmY = kAnimationBodyY - 1;
  const int kAnimationRightArmX = kAnimationBodyX + BodyHumanCharacterSnaps::kWidth,
            kAnimationRightArmY = kAnimationBodyY - 1;
  const int kAnimationLeftLegX = kAnimationBodyX - ArmHumanCharacterSnaps::kWidth + 1,
            kAnimationLeftLegY = kAnimationBodyY + ArmHumanCharacterSnaps::kHeight;
  const int kAnimationRightLegX = kAnimationBodyX + BodyHumanCharacterSnaps::kWidth,
            kAnimationRightLegY = kAnimationBodyY + BodyHumanCharacterSnaps::kHeight;
  
  animation_area_ = std::make_shared<AnimationArea>(0, 0, kAnimationAreaWidth, kAnimationAreaHeight);
  animation_head_ = std::make_shared<HeadHumanCharacterAnimation>(kAnimationHeadX, kAnimationHeadY);
  animation_body_ = std::make_shared<BodyHumanCharacterAnimation>(kAnimationBodyX, kAnimationBodyY);
  animation_left_arm_ = std::make_shared<ArmHumanCharacterAnimation>(kAnimationLeftArmX, 
								     kAnimationLeftArmY,
								     Arm::LEFT);
  animation_right_arm_ = std::make_shared<ArmHumanCharacterAnimation>(kAnimationRightArmX, 
								      kAnimationRightArmY,
								      Arm::RIGHT);
  animation_left_leg_ = std::make_shared<LegHumanCharacterAnimation>(kAnimationLeftLegX, kAnimationLeftLegY);
  animation_right_leg_ = std::make_shared<LegHumanCharacterAnimation>(kAnimationRightLegX, kAnimationRightLegY);

  animation_area_->AddAnimation(animation_head_);
  animation_area_->AddAnimation(animation_body_);
  animation_area_->AddAnimation(animation_left_arm_);
  animation_area_->AddAnimation(animation_right_arm_);
  animation_area_->AddAnimation(animation_left_leg_);
  animation_area_->AddAnimation(animation_right_leg_);
  
  if (screen_ == nullptr) {
    std::cerr << "Error in HumanCharacter::Init(): screen_ == nullptr\n";
    return false;
  }
  screen_->set_main_animation(animation_area_);
  
  return true;
}

void HumanCharacter::ArmUp(Arm arm) {
  if (!is_human_character_ready_) {
    std::cerr << "Error in HumanCharacter::ArmUp(...): HumanCharacter not initialized.\n";
    return;
  }
  if (arm == Arm::LEFT) {
    animation_left_arm_->PlayUpArmAnimation();
  } else { 
    animation_right_arm_->PlayUpArmAnimation();
  }
}

void HumanCharacter::ArmDown(Arm arm) {
  if (!is_human_character_ready_) {
    std::cerr << "Error in HumanCharacter::ArmUp(...): HumanCharacter not initialized.\n";
    return;
  }
  if (arm == Arm::LEFT) {
    animation_left_arm_->PlayDownArmAnimation();
  } else { 
    animation_right_arm_->PlayDownArmAnimation();
  }
  
}
}  // DBusStateMachine
