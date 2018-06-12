#include "human_character_service_impl.h"

#include <iostream>

#include "character_animation.h"
#include "human_character_animation.h"
#include "human_character_service_state.h"

namespace DBusStateMachine {
HumanCharacterServiceImpl::HumanCharacterServiceImpl() {
  initialize_state_  = std::make_shared<ServiceInitializeState>(this);
  ChangeState(initialize_state_);
  
  destroy_state_ = std::make_shared<ServiceDestroyState>(this);
  arm_moving_state_ = std::make_shared<ServiceArmMovingState>(this);
  wait_command_state_ = std::make_shared<ServiceWaitCommandState>(this);
  
  ChangeState(wait_command_state_);
}

HumanCharacterServiceImpl::~HumanCharacterServiceImpl() {
  current_state_ = destroy_state_;
}

void HumanCharacterServiceImpl::ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     		      DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
				      ArmUpReply_t _reply) {
  std::string reply_string;
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    current_state_->LeftArmUp(&reply_string);
  } else {
    current_state_->RightArmUp(&reply_string);
  }
  _reply(reply_string);
}

void HumanCharacterServiceImpl::ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       			DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
					ArmDownReply_t _reply) {
  std::string reply_string;
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    current_state_->LeftArmDown(&reply_string);
  } else {
    current_state_->RightArmDown(&reply_string);
  }
  _reply(reply_string);
}
}  // DBusStateMachine3
