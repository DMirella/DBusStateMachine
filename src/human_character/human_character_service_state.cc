#include "human_character_service_state.h"

#include <future>

#include "human_character_service_impl.h"

namespace DBusStateMachine {
ServiceWaitCommandState::~ServiceWaitCommandState() {
  if (arm_moving_thread_.joinable()) {
    arm_moving_thread_.join();
  }
}

void ServiceWaitCommandState::LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  _reply( "Ok, left arm will be move up.");
  if (arm_moving_thread_.joinable()) {
    arm_moving_thread_.join();
  }
  arm_moving_thread_ = std::thread([this]() {
    human_service_->human_.ArmUp(Arm::LEFT);
    human_service_->ChangeState(human_service_->wait_command_state_);
  });
}

void ServiceWaitCommandState::RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  _reply("Ok, right arm will be move up.");
  if (arm_moving_thread_.joinable()) {
    arm_moving_thread_.join();
  }
  arm_moving_thread_ = std::thread([this]() {
    human_service_->human_.ArmUp(Arm::RIGHT);
    human_service_->ChangeState(human_service_->wait_command_state_);
  });
}

void ServiceWaitCommandState::LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  _reply("Ok, left arm will be move up.");
  if (arm_moving_thread_.joinable()) {
    arm_moving_thread_.join();
  }
  arm_moving_thread_ = std::thread([this]() {
    human_service_->human_.ArmUp(Arm::LEFT);
    human_service_->ChangeState(human_service_->wait_command_state_);
  });
}

void ServiceWaitCommandState::RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) {
  human_service_->ChangeState(human_service_->arm_moving_state_);
  _reply("Ok, right arm will be move up.");
  if (arm_moving_thread_.joinable()) {
    arm_moving_thread_.join();
  }
  arm_moving_thread_ = std::thread([this]() {
    human_service_->human_.ArmUp(Arm::RIGHT);
    human_service_->ChangeState(human_service_->wait_command_state_);
  });
}
}  // DBusStateMachine
