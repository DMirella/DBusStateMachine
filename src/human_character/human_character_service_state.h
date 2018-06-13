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
  
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) = 0;
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) = 0;
 protected:
  HumanCharacterServiceImpl* human_service_;  // not deleted
};

class ServiceInitializeState : public ServiceState {
 public:
  ServiceInitializeState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) { reply("Skipped, service not initializated."); }
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) { reply("Skipped, service not initializated."); }
};

class ServiceDestroyState : public ServiceState {
 public:
  ServiceDestroyState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) { reply("Skipped, service destroying."); }
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) { reply("Skipped, service destroying."); }
};

class ServiceArmsMovingState : public ServiceState {
 public:
  ServiceArmsMovingState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply) { reply("Skipped, arms already moving."); }
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply) { reply("Skipped, arms already moving."); }
};

class ServiceArmsUpState : public ServiceState {
 public:
  ServiceArmsUpState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  ~ServiceArmsUpState();
  // ServiceState
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply);
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply);
 private:
  std::thread arms_moving_thread_;
};

class ServiceArmsDownState : public ServiceState {
 public:
  ServiceArmsDownState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  ~ServiceArmsDownState();
  // ServiceState
  virtual void ArmsUp(HumanCharacterServiceImpl::ArmsUpReply_t reply);
  virtual void ArmsDown(HumanCharacterServiceImpl::ArmsDownReply_t reply);
 private:
  std::thread arms_moving_thread_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_
