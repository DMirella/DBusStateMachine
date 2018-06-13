#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_

#include "human_character_constants.h"
#include "snaps_animation.h"

namespace DBusStateMachine {
enum Arm;
class ArmHumanCharacterAnimation : public SnapsAnimation {
 public:
  ArmHumanCharacterAnimation(const ArmHumanCharacterAnimation& animation) = delete;
  ArmHumanCharacterAnimation(ArmHumanCharacterAnimation&& animation) = delete;
  ArmHumanCharacterAnimation& operator=(const ArmHumanCharacterAnimation& animation) = delete;
  ArmHumanCharacterAnimation& operator=(ArmHumanCharacterAnimation&& animation) = delete;

  ArmHumanCharacterAnimation() {}
  ArmHumanCharacterAnimation(int x, int y, Arm arm);
  ~ArmHumanCharacterAnimation() {}
  
  void PlayUpArmAnimation();
  void PlayDownArmAnimation();
};

class LegHumanCharacterAnimation : public SnapsAnimation {
 public:
  LegHumanCharacterAnimation(const LegHumanCharacterAnimation& animation) = delete;
  LegHumanCharacterAnimation(LegHumanCharacterAnimation&& animation) = delete;
  LegHumanCharacterAnimation& operator=(const LegHumanCharacterAnimation& animation) = delete;
  LegHumanCharacterAnimation& operator=(LegHumanCharacterAnimation&& animation) = delete;

  LegHumanCharacterAnimation() {}
  LegHumanCharacterAnimation(int x, int y);
  ~LegHumanCharacterAnimation() {}
};

class BodyHumanCharacterAnimation : public SnapsAnimation {
 public:
  BodyHumanCharacterAnimation(const BodyHumanCharacterAnimation& animation) = delete;
  BodyHumanCharacterAnimation(BodyHumanCharacterAnimation&& animation) = delete;
  BodyHumanCharacterAnimation& operator=(const BodyHumanCharacterAnimation& animation) = delete;
  BodyHumanCharacterAnimation& operator=(BodyHumanCharacterAnimation&& animation) = delete;

  BodyHumanCharacterAnimation() {}
  BodyHumanCharacterAnimation(int x, int y);
  ~BodyHumanCharacterAnimation() {}
};

class HeadHumanCharacterAnimation : public SnapsAnimation {
 public:
  HeadHumanCharacterAnimation(const HeadHumanCharacterAnimation& animation) = delete;
  HeadHumanCharacterAnimation(HeadHumanCharacterAnimation&& animation) = delete;
  HeadHumanCharacterAnimation& operator=(const HeadHumanCharacterAnimation& animation) = delete;
  HeadHumanCharacterAnimation& operator=(HeadHumanCharacterAnimation&& animation) = delete;

  HeadHumanCharacterAnimation() {}
  HeadHumanCharacterAnimation(int x, int y);
  ~HeadHumanCharacterAnimation() {}
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_
