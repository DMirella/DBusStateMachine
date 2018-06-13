#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_H_

#include <memory>

#include "animation.h"
#include "human_character_animation.h"
#include "human_character_constants.h"

namespace DBusStateMachine {
class AnimationScreen;

class HumanCharacter {
 public:
  HumanCharacter();
  ~HumanCharacter() {}

  void ArmUp(Arm arm);
  void ArmDown(Arm arm);
 private:
  bool Init();

  bool is_human_character_ready_;
  
  std::shared_ptr<AnimationArea> animation_area_;
  std::shared_ptr<HeadHumanCharacterAnimation> animation_head_;
  std::shared_ptr<BodyHumanCharacterAnimation> animation_body_;
  std::shared_ptr<ArmHumanCharacterAnimation> animation_left_arm_, animation_right_arm_;
  std::shared_ptr<LegHumanCharacterAnimation> animation_left_leg_, animation_right_leg_;
  AnimationScreen* screen_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_H_
