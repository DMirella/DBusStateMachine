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
class ServiceArmMovingState;
class ServiceWaitCommandState;
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
  virtual void ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
		     ArmUpReply_t _reply) override;
  virtual void ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
		       ArmDownReply_t _reply) override;
  inline void ChangeState(std::shared_ptr<ServiceState> state) { current_state_ = state; }
 private:
  friend class ServiceWaitCommandState;

  std::shared_ptr<ServiceInitializeState> initialize_state_;
  std::shared_ptr<ServiceDestroyState> destroy_state_;
  std::shared_ptr<ServiceArmMovingState> arm_moving_state_;
  std::shared_ptr<ServiceWaitCommandState> wait_command_state_;

  std::shared_ptr<ServiceState> current_state_;
  HumanCharacter human_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_
