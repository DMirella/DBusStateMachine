#include "human_character_service_impl.h"

#include <iostream>

#include "character_animation.h"
#include "human_character_animation.h"

namespace DBusStateMachine {
void HumanCharacterServiceImpl::ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     		      DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
				      ArmUpReply_t _reply) {
}

void HumanCharacterServiceImpl::ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       			DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
					ArmDownReply_t _reply) {
}
}  // DBusStateMachine
