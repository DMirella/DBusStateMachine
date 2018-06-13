#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_CLIENT_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_CLIENT_H_

#include <memory>
#include <string>

#include "CommonAPI/CommonAPI.hpp"

#include "v1/com/luxoft/humancharacterservice/HumanCharacterServiceProxy.hpp"

namespace DBusStateMachine {
class HumanCharacterServiceClient {
  enum Status { CLIENT_NOT_INIT, SERVICE_NOT_AVAILABLE, READY_TO_USE };
 public:
  HumanCharacterServiceClient() = delete;
  HumanCharacterServiceClient(const HumanCharacterServiceClient& service) = delete;
  HumanCharacterServiceClient(HumanCharacterServiceClient&& service) = delete;
  HumanCharacterServiceClient& operator=(const HumanCharacterServiceClient& service) = delete;
  HumanCharacterServiceClient& operator=(HumanCharacterServiceClient&& service) = delete;
  
  explicit HumanCharacterServiceClient(const std::string& service_name);
  ~HumanCharacterServiceClient() {}

  bool WaitAvailable();

  void ArmsUp();
  void ArmsDown();
 private:
  bool Initialize();
  
  Status status_;
  std::string service_name_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<v1::com::luxoft::humancharacterservice::HumanCharacterServiceProxy<>> service_proxy_;
};



}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_CLIENT_H_
