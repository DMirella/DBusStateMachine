#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_

#include <memory>

#include "CommonAPI/CommonAPI.hpp"

#include "human_character.h"
#include "v1/com/luxoft/humancharacterservice/HumanCharacterServiceStubDefault.hpp"

namespace DBusStateMachine {
namespace DBusHumanCharacterService = v1::com::luxoft::humancharacterservice;

class ServiceInitializeState;
class ServiceDestroyState;
class ServiceArmsMovingState;
class ServiceArmsUpState;
class ServiceArmsDownState;
class ServiceState;

class HumanCharacterServiceImpl 
    : public DBusHumanCharacterService::HumanCharacterServiceStubDefault {
 public:
  HumanCharacterServiceImpl(const HumanCharacterServiceImpl& service) = delete;
  HumanCharacterServiceImpl(HumanCharacterServiceImpl&& service) = delete;
  HumanCharacterServiceImpl& operator=(const HumanCharacterServiceImpl& service) = delete;
  HumanCharacterServiceImpl& operator=(HumanCharacterServiceImpl&& service) = delete;

  HumanCharacterServiceImpl();
  virtual ~HumanCharacterServiceImpl();
  // CharacterServiceStubDefault
  virtual void ArmsUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     ArmsUpReply_t _reply) override;
  virtual void ArmsDown(const std::shared_ptr<CommonAPI::ClientId> _client,
		       ArmsDownReply_t _reply) override;
  inline void ChangeState(std::shared_ptr<ServiceState> state) { current_state_ = state; }
 private:
  friend class ServiceArmsUpState;
  friend class ServiceArmsDownState;

  std::shared_ptr<ServiceInitializeState> initialize_state_;
  std::shared_ptr<ServiceDestroyState> destroy_state_;
  std::shared_ptr<ServiceArmsMovingState> arms_moving_state_;
  std::shared_ptr<ServiceArmsUpState> arms_up_state_;
  std::shared_ptr<ServiceArmsDownState> arms_down_state_;

  std::shared_ptr<ServiceState> current_state_;
  HumanCharacter human_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_
