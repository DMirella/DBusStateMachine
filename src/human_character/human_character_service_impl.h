#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_

#include <memory>

#include "CommonAPI/CommonAPI.hpp"

#include "v1/com/luxoft/humancharacterservice/HumanCharacterServiceStubDefault.hpp"

namespace DBusStateMachine {
namespace DBusHumanCharacterService = v1::com::luxoft::humancharacterservice;

class HumanCharacterAnimation;

class HumanCharacterServiceImpl 
    : public DBusHumanCharacterService::HumanCharacterServiceStubDefault {
  //class HumanCharacterState;
 public:
  HumanCharacterServiceImpl() = delete;
  HumanCharacterServiceImpl(const HumanCharacterServiceImpl& service) = delete;
  HumanCharacterServiceImpl(HumanCharacterServiceImpl&& service) = delete;
  HumanCharacterServiceImpl& operator=(const HumanCharacterServiceImpl& service) = delete;
  HumanCharacterServiceImpl& operator=(HumanCharacterServiceImpl&& service) = delete;

  explicit HumanCharacterServiceImpl(HumanCharacterAnimation* animation);
  virtual ~HumanCharacterServiceImpl() {}
  // CharacterServiceDefault
  virtual void ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
		     DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
		     ArmUpReply_t _reply) override;
  virtual void ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       DBusHumanCharacterService::HumanCharacterService::Arm _arm, 
		       ArmDownReply_t _reply) override;
 private:
  //std::unique_ptr<HumanCharacterState> state_;
  HumanCharacterAnimation* animation_;  // not deleted
};

class HumanCharacterState {};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_IMPL_H_
