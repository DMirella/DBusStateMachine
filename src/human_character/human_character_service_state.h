#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_

#include <string>

namespace DBusStateMachine {
class HumanCharacterServiceImpl;
class ServiceState {
 public:
  ServiceState(HumanCharacterServiceImpl* human_service) : human_service_(human_service) {}
  virtual ~ServiceState() {}
  
  virtual void LeftArmUp(std::string* reply) = 0;
  virtual void RightArmUp(std::string* reply) = 0;
  virtual void LeftArmDown(std::string* reply) = 0;
  virtual void RightArmDown(std::string* reply) = 0;
 protected:
  HumanCharacterServiceImpl* human_service_;
};

class ServiceInitializeState : public ServiceState {
 public:
  ServiceInitializeState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(std::string* reply) override { *reply = "Skipped, service not initialized, yet."; }
  virtual void RightArmUp(std::string* reply) override { *reply = "Skipped, service not initialized, yet."; }
  virtual void LeftArmDown(std::string* reply) override { *reply = "Skipped, service not initialized, yet."; }
  virtual void RightArmDown(std::string* reply) override { *reply = "Skipped, service not initialized, yet."; }
};

class ServiceDestroyState : public ServiceState {
 public:
  ServiceDestroyState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(std::string* reply) override { *reply = "Skipped, service finishing work."; }
  virtual void RightArmUp(std::string* reply) override { *reply = "Skipped, service finishing work."; }
  virtual void LeftArmDown(std::string* reply) override { *reply = "Skipped, service finishing work."; }
  virtual void RightArmDown(std::string* reply) override { *reply = "Skipped, service finishing work."; }
};

class ServiceArmMovingState : public ServiceState {
 public:
  ServiceArmMovingState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(std::string* reply) override { *reply = "Skipped, arm always moving."; }
  virtual void RightArmUp(std::string* reply) override { *reply = "Skipped, arm always moving."; }
  virtual void LeftArmDown(std::string* reply) override { *reply = "Skipped, arm always moving."; }
  virtual void RightArmDown(std::string* reply) override { *reply = "Skipped, arm always moving."; }
};

class ServiceWaitCommandState : public ServiceState {
 public:
  ServiceWaitCommandState(HumanCharacterServiceImpl* human_service) : ServiceState(human_service) {}
  // ServiceState
  virtual void LeftArmUp(std::string* reply) override;
  virtual void RightArmUp(std::string* reply) override;
  virtual void LeftArmDown(std::string* reply) override;
  virtual void RightArmDown(std::string* reply) override;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_STATE_H_
