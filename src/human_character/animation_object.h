#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_OBJECT_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_OBJECT_H_

#include <vector>

namespace DBusStateMachine {
class Pixel {
 public:
  inline char ToChar() { return color_; }
 private:
  char color_;
};

class Sprite {
 public:
  inline std::vector<std::vector<Pixel>> image() { return image_; }
 private:
  std::vector<std::vector<Pixel>> image_;
};

class AnimationObject {
 public:
  virtual ~AnimationObject() {}
  virtual Sprite MakeSnapshot() const = 0;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_OBJECT_H_
