#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_

#include "animation.h"
#include "character_animation.h"

namespace DBusStateMachine {
class ArmHumanCharacterAnimation : public CharacterAnimation {
 public:
  enum Arm {LEFT, RIGHT};

  ArmHumanCharacterAnimation(const ArmHumanCharacterAnimation& animation) = delete;
  ArmHumanCharacterAnimation(ArmHumanCharacterAnimation&& animation) = delete;
  ArmHumanCharacterAnimation& operator=(const ArmHumanCharacterAnimation& animation) = delete;
  ArmHumanCharacterAnimation& operator=(ArmHumanCharacterAnimation&& animation) = delete;

  ArmHumanCharacterAnimation() {}
  ArmHumanCharacterAnimation(int x, int y, Arm arm);
  virtual ~ArmHumanCharacterAnimation() {}
  
  void Up() const;
  void Down() const;
 private:
  Arm arm_;
};

class LegHumanCharacterAnimation : public CharacterAnimation {
 public:
  LegHumanCharacterAnimation(const LegHumanCharacterAnimation& animation) = delete;
  LegHumanCharacterAnimation(LegHumanCharacterAnimation&& animation) = delete;
  LegHumanCharacterAnimation& operator=(const LegHumanCharacterAnimation& animation) = delete;
  LegHumanCharacterAnimation& operator=(LegHumanCharacterAnimation&& animation) = delete;

  LegHumanCharacterAnimation() {}
  LegHumanCharacterAnimation(int x, int y);
  virtual ~LegHumanCharacterAnimation() {}
};

class BodyHumanCharacterAnimation : public CharacterAnimation {
 public:
  BodyHumanCharacterAnimation(const BodyHumanCharacterAnimation& animation) = delete;
  BodyHumanCharacterAnimation(BodyHumanCharacterAnimation&& animation) = delete;
  BodyHumanCharacterAnimation& operator=(const BodyHumanCharacterAnimation& animation) = delete;
  BodyHumanCharacterAnimation& operator=(BodyHumanCharacterAnimation&& animation) = delete;

  BodyHumanCharacterAnimation() {}
  BodyHumanCharacterAnimation(int x, int y);
  virtual ~BodyHumanCharacterAnimation() {}
};

class HeadHumanCharacterAnimation : public CharacterAnimation {
 public:
  HeadHumanCharacterAnimation(const HeadHumanCharacterAnimation& animation) = delete;
  HeadHumanCharacterAnimation(HeadHumanCharacterAnimation&& animation) = delete;
  HeadHumanCharacterAnimation& operator=(const HeadHumanCharacterAnimation& animation) = delete;
  HeadHumanCharacterAnimation& operator=(HeadHumanCharacterAnimation&& animation) = delete;

  HeadHumanCharacterAnimation() {}
  HeadHumanCharacterAnimation(int x, int y);
  virtual ~HeadHumanCharacterAnimation() {}
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_ANIMATION_H_
