#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_

#include <string>
#include <vector>

#include "animation.h"

namespace DBusStateMachine {
std::vector<Snap> StringsToSnaps(const std::vector<std::vector<std::string>>& strings) {
  std::vector<Snap> result;
  for (auto& current_vector : strings) {
    std::vector<std::vector<Pixel>> current_vector_pixels;
    for (auto& current_string : current_vector) {
      int current_length = current_string.length();
      std::vector<Pixel> current_pixels;
      for (int i = 0; i < current_length; ++i) {
        current_pixels.emplace_back(current_string[i]);
      }
      current_vector_pixels.emplace_back(current_pixels);
    }
    result.emplace_back(current_vector_pixels);
  }
  return result;
}

namespace ArmHumanCharacterSnaps {
const int kWidth = 2, kHeight = 3, kSpeed = 2;
static const std::vector<std::vector<std::string>> kLeftArmSnaps = 
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
    {{"*"},
     {"*"}}
  };
}  // LegHumanCharacterSnaps

namespace BodyHumanCharacterSnaps {
const int kWidth = 1, kHeight = 3, kSpeed = 0;
const std::vector<std::vector<std::string>> kSnaps = 
  { 
    {{"*"},
     {"*"},
     {"*"}}
  };
}  // BodyHumanCharacterSnaps

namespace HeadHumanCharacterSnaps {
const int kWidth = 3, kHeight = 3, kSpeed = 0;
const std::vector<std::vector<std::string>> kSnaps = 
  { 
    {{" * "},
     {"* *"},
     {" * "}}
  };
}  // HeadHumanCharacterSnaps
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SNAPS_H_
