#ifndef DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_H_
#define DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_H_

#include <memory>
#include <string>

#include "CommonAPI/CommonAPI.hpp"

namespace DBusStateMachine {
class CharacterServiceImpl;

class CharacterService {
 public:
  CharacterService(const CharacterService& service)
  CharacterService();

  void StartService();
 private:
  bool Initialize();

  bool is_service_ready_;
  std::shared_ptr<CommonAPI::Runtime> runtime_;
  std::shared_ptr<CharacterServiceImpl> service_;
};
}  // DBusStateMachine

#endif  // DBUSSTATEMACHINE_SRC_CHARACTER_CHARACTER_SERVICE_IMPL_H_
