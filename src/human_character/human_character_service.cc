#include "human_character_service.h"

#include <iostream>

namespace DBusStateMachine {
HumanCharacterService::HumanCharacterService(const std::string& service_name) 
    : service_name_(service_name), runtime_(nullptr), service_(nullptr), is_service_ready_(false) {
  if (!(is_service_ready_ = Initialize())) {
    std::cerr << "Initialization failed!\n";
  }
}

bool HumanCharacterService::Initialize() {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error in HumanCharacterService::Initialize(): runtime_ == nullptr\n";
    return false;
  }
  service_ = std::make_shared<HumanCharacterServiceImpl>();
  if (service_ == nullptr) {
    std::cerr << "Error in HumanCharacterService::Initialize(): service_ == nullptr\n";
    return false;
  }
  runtime_->registerService("", service_name_, service_);
  return true;
}
}  // DBusStateMachine
