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
  arms_moving_state_ = std::make_shared<ServiceArmsMovingState>(this);
  arms_up_state_ = std::make_shared<ServiceArmsUpState>(this);
  arms_down_state_ = std::make_shared<ServiceArmsDownState>(this);
  
  ChangeState(arms_down_state_);
}

HumanCharacterServiceImpl::~HumanCharacterServiceImpl() {
  ChangeState(destroy_state_);
}

void HumanCharacterServiceImpl::ArmsUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
				       ArmsUpReply_t _reply) {
  //std::cout << "Up command.\n";
  current_state_->ArmsUp(_reply);
 // std::cout << "Up command2.\n";
}

void HumanCharacterServiceImpl::ArmsDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
					 ArmsDownReply_t _reply) {
  //std::cout << "Down command.\n";
  current_state_->ArmsDown(_reply);
  //std::cout << "Down command2.\n";
}
}  // DBusStateMachine3
