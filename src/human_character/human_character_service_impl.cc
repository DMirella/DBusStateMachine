#include "human_character_service_impl.h"

#include <iostream>

#include "character_animation.h"

namespace DBusStateMachine {
HumanCharacterServiceImpl::HumanCharacterServiceImpl(HumanCharacterAnimation* animation)
    : animation_(animation) {
  if (animation_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceImpl::HumanCharacterServiceImpl(...): animation_ == nullptr\n";
  }
}

void HumanCharacterServiceImpl::ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     		      DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
				      ArmUpReply_t _reply) {
  if (animation_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceImpl::ArmUp(...): animation_ == nullptr\n";
    _reply("Service error.\n");
  }
}

void HumanCharacterServiceImpl::ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       			DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
					ArmDownReply_t _reply) {
  if (animation_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceImpl::ArmDown(...): animation_ == nullptr\n";
    _reply("Service error.\n");
  }
}
}  // DBusStateMachine
