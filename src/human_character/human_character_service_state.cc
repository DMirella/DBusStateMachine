#include "human_character_service_state.h"

#include <future>
#include <iostream>

#include "human_character_service_impl.h"

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
  //std::cout << "try to start arms_moving_thread_ ::ArmsUpState\n";
  arms_moving_thread_ = std::thread([this]() {
				      human_service_->human_.ArmDown(Arm::LEFT);
				      human_service_->human_.ArmDown(Arm::RIGHT);
				     // std::cout << "arms_up_thread_ end ::ArmsUpState\n";
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
  //std::cout << "try to start arms_moving_thread_ ::ArmsDownState\n";
  arms_moving_thread_ = std::thread([this]() {
				      human_service_->human_.ArmUp(Arm::LEFT);
				     // std::cout << "human_service_::LEFT end.\n";
				      human_service_->human_.ArmUp(Arm::RIGHT);
				      //std::cout << "arms_moving_thread_ end ::ArmsDownState\n";
  				      human_service_->ChangeState(human_service_->arms_up_state_);
                                    });
}

void ServiceArmsDownState::ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) {
  reply("Skipped, arms already moved down.");
}
}  // DBusStateMachine
