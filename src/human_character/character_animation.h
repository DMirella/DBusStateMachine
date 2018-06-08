#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_

#include <vector>

#include "animation_object.h"

namespace DBusStateMachine {
class CharacterAnimation : public AnimationObject {
 public:
  virtual ~CharacterAnimation() {}
 protected:
  CharacterAnimation(int speed, const std::vector<Sprite>& sprites);
  
  int speed_;
  std::vector<Sprite> sprites_;
};

class ArmCharacterAnimation : public CharacterAnimation {
 public:
  ArmCharacterAnimation() = delete;
  ArmCharacterAnimation(const ArmCharacterAnimation& service) = delete;
  ArmCharacterAnimation(ArmCharacterAnimation&& service) = delete;
  ArmCharacterAnimation& operator=(const ArmCharacterAnimation& service) = delete;
  ArmCharacterAnimation& operator=(ArmCharacterAnimation&& service) = delete;
  
  void Up() const;
  void Down() const;
  // CharacterAnimation
  virtual Sprite MakeSnapshot() const override;
};

class LegCharacterAnimation : public CharacterAnimation {
 public:
  LegCharacterAnimation() = delete; 
  LegCharacterAnimation(const LegCharacterAnimation& service) = delete;
  LegCharacterAnimation(LegCharacterAnimation&& service) = delete;
  LegCharacterAnimation& operator=(const LegCharacterAnimation& service) = delete;
  LegCharacterAnimation& operator=(LegCharacterAnimation&& service) = delete;
  // CharacterAnimation
  virtual Sprite MakeSnapshot() const override;
};

class BodyCharacterAnimation : public CharacterAnimation {
 public:
  BodyCharacterAnimation() = delete;
  BodyCharacterAnimation(const BodyCharacterAnimation& service) = delete;
  BodyCharacterAnimation(BodyCharacterAnimation&& service) = delete;
  BodyCharacterAnimation& operator=(const BodyCharacterAnimation& service) = delete;
  BodyCharacterAnimation& operator=(BodyCharacterAnimation&& service) = delete;
  // CharacterAnimation
  virtual Sprite MakeSnapshot() const override;
};

}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
