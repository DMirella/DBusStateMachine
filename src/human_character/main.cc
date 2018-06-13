#include <chrono>
#include <iostream>
#include <thread>

#include "human_character_service.h"

int main() {
  const auto kMainTimeOutMs = std::chrono::milliseconds(10000);
  const std::string kServiceName = "HumanService";
  DBusStateMachine::HumanCharacterService human_service(kServiceName);
  std::cout << "Server was started, wait for clients...\n";

  std::this_thread::sleep_for(kMainTimeOutMs);
  return 0;
}
