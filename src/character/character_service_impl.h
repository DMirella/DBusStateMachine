#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_IMPL_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_IMPL_H_

#include <memory>
#include <string>

#include "v1/com/luxoft/characterservice/CharacterServiceDefault.hpp"

namespace DBusStateMachine {
class CharacterState;
class CharacterAnimation;

class CharacterServiceImpl 
    : public v1::com::luxoft::characterservice::CharacterServiceDefault {
 public:
  CharacterServiceImpl() = delete;
  CharacterServiceImpl(const CharacterServiceImpl& service) = delete;
  CharacterServiceImpl(CharacterServiceImpl&& service) = delete;
  CharacterServiceImpl& operator=(const CharacterServiceImpl& service) = delete;
  CharacterServiceImpl& operator=(CharacterServiceImpl&& service) = delete;

  CharacterServiceImpl(CharacterAnimation* animation);
  virtual ~CharacterServiceImpl();
  // CharacterServiceDefault
  virtual void ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
                     CharacterService::Arm _arm, ArmUpReply_t _reply) override;
  virtual void ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
		       CharacterService::Arm _arm, ArmDownReply_t _reply) override;
 private:
  std::unique_ptr<CharacterState> state_;
  CharacterAnimation* animation_;  // not deleted
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_IMPL_H_
