#include "human_character_service_impl.h"

#include <iostream>

#include "character_animation.h"
#include "human_character_animation.h"

namespace DBusStateMachine {
void HumanCharacterServiceImpl::ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     		      DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
				      ArmUpReply_t _reply) {
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    human_.ArmUp(Arm::LEFT);
  } else {
    human_.ArmUp(Arm::RIGHT);
  }
}

void HumanCharacterServiceImpl::ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       			DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
					ArmDownReply_t _reply) {
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    human_.ArmDown(Arm::LEFT);
  } else {
    human_.ArmDown(Arm::RIGHT);
  }
}
}  // DBusStateMachine3
