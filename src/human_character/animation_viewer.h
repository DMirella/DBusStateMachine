#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_VIEWER_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_VIEWER_H_

#include <memory>
#include <vector>

namespace DBusStateMachine {

class AnimationObject;
class AnimationViewer {
 public:
  AnimationViewer() = delete;
  AnimationViewer(const AnimationViewer& service) = delete;
  AnimationViewer(AnimationViewer&& service) = delete;
  AnimationViewer& operator=(const AnimationViewer& service) = delete;
  AnimationViewer& operator=(AnimationViewer&& service) = delete;
  
  inline static std::weak_ptr<AnimationViewer> instance() { return instance_; }
 private:
  static std::shared_ptr<AnimationObject> instance_;
  std::vector<AnimationObject*> animation_objects_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_VIEWER_H_
