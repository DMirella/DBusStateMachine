#include "human_character_service_state.h"

#include "human_character_service_impl.h"

namespace DBusStateMachine {
void ServiceWaitCommandState::LeftArmUp(std::string* reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  *reply = "Ok, left arm will be move up."; 
  human_service_->human_.ArmUp(Arm::LEFT);
  human_service_->ChangeState(human_service_->wait_command_state_);
}

void ServiceWaitCommandState::RightArmUp(std::string* reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  *reply = "Ok, right arm will be move up."; 
  human_service_->human_.ArmUp(Arm::RIGHT);
  human_service_->ChangeState(human_service_->wait_command_state_);
}

void ServiceWaitCommandState::LeftArmDown(std::string* reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  *reply = "Ok, left arm will be move up."; 
  human_service_->human_.ArmUp(Arm::LEFT);
  human_service_->ChangeState(human_service_->wait_command_state_);
}

void ServiceWaitCommandState::RightArmDown(std::string* reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  *reply = "Ok, right arm will be move up."; 
  human_service_->human_.ArmUp(Arm::RIGHT);
  human_service_->ChangeState(human_service_->wait_command_state_);
}
}  // DBusStateMachine
