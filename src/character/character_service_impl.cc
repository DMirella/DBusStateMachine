#include "character_service_impl.h"

namespace DBusStateMachine {
CharacterServiceImpl::CharacterServiceImpl(CharacterAnimation* animation)
    : animation_(animation) {
}

CharacterServiceImpl::~CharacterServiceImpl() {
}

void ArmUp(const std::shared_ptr<CommonAPI::ClientId> _client, 
           CharacterService::Arm _arm, ArmUpReply_t _reply) {
  
}

void ArmDown(const std::shared_ptr<CommonAPI::ClientId> _client, 
             CharacterService::Arm _arm, ArmUpReply_t _reply) {
  
}
}  // DBusStateMachine
