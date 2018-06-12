#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_

#include <string>
#include <thread>

#include "human_character_service_impl.h"

namespace DBusStateMachine {
class ServiceState {
 public:
  ServiceState(HumanCharacterServiceImpl* human_service) : human_service_(human_service) {}
  virtual ~ServiceState() {}
  
  virtual void LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) = 0;
  virtual void RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) = 0;
  virtual void LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) = 0;
  virtual void RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) = 0;
 protected:
  HumanCharacterServiceImpl* human_service_;
};

class ServiceInitializeState : public ServiceState {
 public:
  ServiceInitializeState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, service not initialized, yet."); }
  virtual void RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, service not initialized, yet."); }
  virtual void LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, service not initialized, yet."); }
  virtual void RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, service not initialized, yet."); }
};

class ServiceDestroyState : public ServiceState {
 public:
  ServiceDestroyState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, service finishing work."); }
  virtual void RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, service finishing work."); }
  virtual void LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, service finishing work."); }
  virtual void RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, service finishing work."); }
};

class ServiceArmMovingState : public ServiceState {
 public:
  ServiceArmMovingState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, arm always moving."); }
  virtual void RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override { _reply("Skipped, arm always moving."); }
  virtual void LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, arm always moving."); }
  virtual void RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override { _reply("Skipped, arm always moving."); }
};

class ServiceWaitCommandState : public ServiceState {
 public:
  ServiceWaitCommandState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  ~ServiceWaitCommandState();
  // ServiceState
  virtual void LeftArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override;
  virtual void RightArmUp(HumanCharacterServiceImpl::ArmUpReply_t _reply) override;
  virtual void LeftArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override;
  virtual void RightArmDown(HumanCharacterServiceImpl::ArmDownReply_t _reply) override;
 private:
  std::thread arm_moving_thread_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_
