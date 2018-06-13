#include "human_character_service_state.h"

namespace DBusStateMachine {
ServiceArmsUpState::~ServiceArmsUpState() {
  if (arms_moving_thread_.joinable()) {
    arms_moving_thread_.join();
  }
}

void ServiceArmsUpState::ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) {
  reply("Skipped, arms already moved up.");
}

void ServiceArmsUpState::ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) {
  if (arms_moving_thread_.joinable()) {
    arms_moving_thread_.join();
  }
  human_service_->ChangeState(human_service_->arms_moving_state_);
  reply("Ok, arms will be moved down.");
  arms_moving_thread_ = std::thread([this]() {
				      human_service_->human_.ArmDown(Arm::LEFT);
				      human_service_->human_.ArmDown(Arm::RIGHT);
  				      human_service_->ChangeState(human_service_->arms_down_state_);
                                    });
}

ServiceArmsDownState::~ServiceArmsDownState() {
  if (arms_moving_thread_.joinable()) {
    arms_moving_thread_.join();
  }
}

void ServiceArmsDownState::ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) {
  if (arms_moving_thread_.joinable()) {
    arms_moving_thread_.join();
  }
  human_service_->ChangeState(human_service_->arms_moving_state_);
  reply("Ok, arms will be moved up.");
  arms_moving_thread_ = std::thread([this]() {
				      human_service_->human_.ArmUp(Arm::LEFT);
				      human_service_->human_.ArmUp(Arm::RIGHT);
  				      human_service_->ChangeState(human_service_->arms_up_state_);
                                    });
}

void ServiceArmsDownState::ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) {
  reply("Skipped, arms already moved down.");
}
}  // DBusStateMachine
