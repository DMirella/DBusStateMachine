#include "human_character_animation.h"

#include "human_character_snaps.h"

#include <iostream>

namespace DBusStateMachine {
namespace {
std::vector<Snap> StringsToSnaps(const std::vector<std::vector<std::string>>& strings) {
  std::vector<Snap> result;
  for (auto& current_vector : strings) {
    std::vector<std::vector<Pixel>> current_vector_pixels;
    for (auto& current_string : current_vector) {
      int current_length = current_string.length();
      std::vector<Pixel> current_pixels;
      for (int i = 0; i < current_length; ++i) {
        current_pixels.emplace_back(Pixel(current_string[i]));
      }
      current_vector_pixels.emplace_back(current_pixels);
    }
    result.emplace_back(current_vector_pixels);
  }
  return result;
}
}  // namespace

ArmHumanCharacterAnimation::ArmHumanCharacterAnimation(int x, int y, Arm arm) 
    : CharacterAnimation(x, y, ArmHumanCharacterSnaps::kWidth, ArmHumanCharacterSnaps::kHeight, 
			 StringsToSnaps((arm == Arm::LEFT)? ArmHumanCharacterSnaps::kLeftArmSnaps 
			     : ArmHumanCharacterSnaps::kRightArmSnaps), ArmHumanCharacterSnaps::kSpeed), arm_(arm) {
}

LegHumanCharacterAnimation::LegHumanCharacterAnimation(int x, int y) 
    : CharacterAnimation(x, y, LegHumanCharacterSnaps::kWidth, LegHumanCharacterSnaps::kHeight, 
			 StringsToSnaps(LegHumanCharacterSnaps::kSnaps), LegHumanCharacterSnaps::kSpeed) {
}

BodyHumanCharacterAnimation::BodyHumanCharacterAnimation(int x, int y) 
    : CharacterAnimation(x, y, BodyHumanCharacterSnaps::kWidth, BodyHumanCharacterSnaps::kHeight, 
			 StringsToSnaps(BodyHumanCharacterSnaps::kSnaps), BodyHumanCharacterSnaps::kSpeed) {
}

HeadHumanCharacterAnimation::HeadHumanCharacterAnimation(int x, int y) 
    : CharacterAnimation(x, y, HeadHumanCharacterSnaps::kWidth, HeadHumanCharacterSnaps::kHeight, 
			 StringsToSnaps(HeadHumanCharacterSnaps::kSnaps), HeadHumanCharacterSnaps::kSpeed) {
}

void ArmHumanCharacterAnimation::Up() const {
  /*const int kTimoutNs = 1000000 / speed_;
  for (current_snap_ = snaps_.begin(); current_snap_ != snaps_.end(); ++current_snap_) {
    usleep(kTimoutNs);
  }*/
}

void ArmHumanCharacterAnimation::Down() const {
  /*const int kTimoutNs = 1000000 / speed_;
  for (current_snap_ = snaps_.rbegin(); current_snap_ != snaps_.rend(); --current_snap_) {
    usleep(kTimoutNs);
  }*/
}
}  // DBusStateMachine
