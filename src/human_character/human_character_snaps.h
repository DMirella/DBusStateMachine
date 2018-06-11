#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_

#include <string>
#include <vector>

#include "animation.h"

namespace DBusStateMachine {
namespace ArmHumanCharacterSnaps {
const int kWidth = 2, kHeight = 3, kSpeed = 2;
const std::vector<std::vector<std::string>> kLeftArmSnaps = 
  { 
    {"  ",
     " *",
     "* "},
    {"  ",
     "**",
     "  "},
    {"* ",
     " *",
     "  "}
  };
const std::vector<std::vector<std::string>> kRightArmSnaps = 
  { 
    {"  ",
     "* ",
     " *"},
    {"  ",
     "**",
     "  "},
    {" *",
     "* ",
     "  "}
  };
}  // ArmHumanCharacterSnaps

namespace LegHumanCharacterSnaps {
const int kWidth = 1, kHeight = 2, kSpeed = 0;
const std::vector<std::vector<std::string>> kSnaps = 
  { 
    {"*",
     "*"}
  };
}  // LegHumanCharacterSnaps

namespace BodyHumanCharacterSnaps {
const int kWidth = 1, kHeight = 3, kSpeed = 0;
const std::vector<std::vector<std::string>> kSnaps = 
  { 
    {"*",
     "*",
     "*"}
  };
}  // BodyHumanCharacterSnaps

namespace HeadHumanCharacterSnaps {
const int kWidth = 3, kHeight = 3, kSpeed = 0;
const std::vector<std::vector<std::string>> kSnaps = 
  { 
    {" * ",
     "*^*",
     " * "}
  };
}  // HeadHumanCharacterSnaps
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_
