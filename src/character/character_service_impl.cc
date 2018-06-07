#include "character_service_impl.h"

#include <iostream>

namespace DBusStateMachine {
CharacterServiceImpl::CharacterServiceImpl(CharacterAnimation* animation)
    : animation_(animation) {
  if (animation_ == nullptr) {
    std::cerr << "Error in CharacterServiceImpl::CharacterServiceImpl(...): animation_ == nullptr\n";
  }
}

CharacterServiceImpl::~CharacterServiceImpl() {
}

void ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
           CharacterService::Arm _arm, ArmUpReply_t _reply) {
  if (animation_ == nullptr) {
    std::cerr << "Error in CharacterServiceImpl::CharacterServiceImpl(...): animation_ == nullptr\n";
    _reply("Service error.\n");
  }
}

void ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
             CharacterService::Arm _arm, ArmUpReply_t _reply) {
  if (animation_ == nullptr) {
    std::cerr << "Error in CharacterServiceImpl::CharacterServiceImpl(...): animation_ == nullptr\n";
    _reply("Service error.\n");
  }
}
}  // DBusStateMachine
