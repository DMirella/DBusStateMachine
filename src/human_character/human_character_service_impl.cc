#include "human_character_service_impl.h"

#include <future>
#include <iostream>
#include <thread>

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
  std::cout << "Up command.\n";
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    current_state_->LeftArmUp(_reply);
  } else {
    current_state_->RightArmUp(_reply);
  }
  std::cout << "Up command2.\n";
}

void HumanCharacterServiceImpl::ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       			DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
					ArmDownReply_t _reply) {
  std::cout << "Down command.\n";
  if (_arm == DBusHumanCharacterService::HumanCharacterService::Arm::LEFT) {
    current_state_->LeftArmDown(_reply);
  } else {
    current_state_->RightArmDown(_reply);
  }
  std::cout << "Down command2.\n";
}
}  // DBusStateMachine3
