#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_

#include <list>

namespace DBusStateMachine {
class HumanCharacterAnimation {
 public:
};

class Sprite;
class ArmCharacterAnimation {
 public:
  ArmCharacterAnimation() = delete;
  ArmCharacterAnimation(const ArmCharacterAnimation& service) = delete;
  ArmCharacterAnimation(ArmCharacterAnimation&& service) = delete;
  ArmCharacterAnimation& operator=(const ArmCharacterAnimation& service) = delete;
  ArmCharacterAnimation& operator=(ArmCharacterAnimation&& service) = delete;
 private:
  std::list<Sprite> sprite_list_;
};

}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
