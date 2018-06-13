#include "human_character_service_impl.h"

#include "human_character_service_state.h"

namespace DBusStateMachine {
HumanCharacterServiceImpl::HumanCharacterServiceImpl() {
  ChangeState(initialize_state_ = std::make_shared<ServiceInitializeState>(this));

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
  if (current_state_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceImpl::ArmsUp(...): current_state_ == nullptr\n";
    _reply("Service error.");
  }
  current_state_->ArmsUp(_reply);
}

void HumanCharacterServiceImpl::ArmsDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
					 ArmsDownReply_t _reply) {
  if (current_state_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceImpl::ArmsDown(...): current_state_ == nullptr\n";
    _reply("Service error.");
  }
  current_state_->ArmsDown(_reply);
}
}  // DBusStateMachine3
