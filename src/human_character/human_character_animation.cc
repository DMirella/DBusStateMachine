#include "human_character_animation.h"

#include "human_character_snaps.h"

namespace DBusStateMachine {
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
