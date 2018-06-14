#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_SNAPS_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_SNAPS_ANIMATION_H_

#include <vector>

#include "animation.h"

namespace DBusStateMachine {
class SnapsAnimation : public AnimationObject {
 public:
  virtual ~SnapsAnimation() {}
  // CharacterAnimation
  virtual Snap MakeSnap() const override { return *current_snap_; }
 protected:
  inline void set_current_snap(const std::vector<Snap>::iterator& snap) { current_snap_ = snap; }

  SnapsAnimation() : current_snap_(snaps_.begin()) {}
  SnapsAnimation(int x, int y, int width, int height, const std::vector<Snap>& snaps, int speed)
    : AnimationObject(x, y, width, height), snaps_(snaps), speed_(speed), current_snap_(snaps_.begin()) {}

  std::vector<Snap> snaps_;
  int speed_;  // count snap views for one second
 private:
  std::vector<Snap>::iterator current_snap_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_SNAPS_ANIMATION_H_
