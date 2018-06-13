#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_H_

#include <memory>
#include <string>

#include "CommonAPI/CommonAPI.hpp"

namespace DBusStateMachine {
class HumanCharacterServiceImpl;

class HumanCharacterService {
 public:
  HumanCharacterService() = delete;
  HumanCharacterService(const HumanCharacterService& service) = delete;
  HumanCharacterService(HumanCharacterService&& service) = delete;
  HumanCharacterService& operator=(const HumanCharacterService& service) = delete;
  HumanCharacterService& operator=(HumanCharacterService&& service) = delete;
  
  explicit HumanCharacterService(const std::string& service_name);
  ~HumanCharacterService() {}
 private:
  bool Initialize();

  bool is_service_ready_;
  std::string service_name_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<HumanCharacterServiceImpl> service_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_HUMAN_CHARACTER_SERVICE_H_
