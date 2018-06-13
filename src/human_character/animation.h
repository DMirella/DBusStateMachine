#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_H_

#include <memory>
#include <vector>

namespace DBusStateMachine {
class Pixel {
 public:
  Pixel() = delete;
  Pixel(const Pixel& pixel) = default;
  Pixel(Pixel&& pixel) = default;
  Pixel& operator=(const Pixel& pixel) = default;
  Pixel& operator=(Pixel&& pixel) = default;

  explicit Pixel(char color) : color_(color) {}
  ~Pixel() {}

  inline char ToChar() const { return color_; }
  bool operator==(const Pixel& r_pixel) const { return color_ == r_pixel.color_; }
  bool operator!=(const Pixel& r_pixel) const { return color_ != r_pixel.color_; }
 private:
  char color_;
};
using PixelMap = std::vector<std::vector<Pixel>>;
const Pixel kEmptyPixel = Pixel(' ');

class Snap {
 public:
  Snap() = delete;
  Snap(const Snap& snap) = default;
  Snap(Snap&& snap) = default;
  Snap& operator=(const Snap& snap) = default;
  Snap& operator=(Snap&& snap) = default;
  
  explicit Snap(PixelMap image) : image_(image) {}
  Snap(int width, int height, Pixel pixel) 
    : width_(width), height_(height), 
      image_(std::vector<std::vector<Pixel>>(height, std::vector<Pixel>(width, pixel))) {}

  inline PixelMap image() const { return image_; }
 private:
  int width_, height_;
  PixelMap image_;
};

class Animation {
 public:
  Animation() : x_(0), y_(0), width_(0), height_(0) {}
  Animation(int x, int y, int width, int height) 
    : x_(x), y_(y), width_(width), height_(height) {}
  virtual ~Animation() {}
  // You must override this function with code, 
  // which make snap of your current object view.
  virtual Snap MakeSnap() const = 0;

  inline int x() { return x_; }
  inline int y() { return y_; }
  inline int width() { return width_; }
  inline int height() { return height_; }
 protected:
  int x_, y_, width_, height_;
};

class AnimationObject : public Animation {
 public:
  AnimationObject() {}
  AnimationObject(int x, int y, int width, int height)
    : Animation(x, y, width, height) {}
  virtual ~AnimationObject() {}
};

class AnimationArea : public Animation {
 public:
  AnimationArea(const AnimationArea& area) = delete;
  AnimationArea(AnimationArea&& area) = delete;
  AnimationArea& operator=(const AnimationArea& area) = delete;
  AnimationArea& operator=(AnimationArea&& area) = delete;

  AnimationArea() {}
  AnimationArea(int x, int y, int width, int height)
    : Animation(x, y, width, height) {}
  virtual ~AnimationArea() {}

  void AddAnimation(const std::shared_ptr<Animation>& animation);
  // Animation
  virtual Snap MakeSnap() const override;
 private:
  std::vector<std::shared_ptr<Animation>> animations_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_ANIMATION_H_
