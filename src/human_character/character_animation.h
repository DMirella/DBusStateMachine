#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_

#include <vector>

#include "animation.h"

namespace DBusStateMachine {
class CharacterAnimation : public AnimationObject {
 public:
  virtual ~CharacterAnimation() {}
  // CharacterAnimation
  virtual Snap MakeSnap() const override { return *current_snap_; }
 protected:
  CharacterAnimation() : current_snap_(snaps_.begin()) {}
  CharacterAnimation(int x, int y, int width, int height, const std::vector<Snap>& snaps, int speed)
    : AnimationObject(x, y, width, height), snaps_(snaps), speed_(speed), current_snap_(snaps_.begin()) {}

  std::vector<Snap> snaps_;
  std::vector<Snap>::iterator current_snap_;
  int speed_;  // count snap views for one second

};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_ANIMATION_H_
