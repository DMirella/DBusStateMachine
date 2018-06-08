#include <unistd.h>

#include <iostream>

#include "human_character_service.h"

int main() {
  const auto kMainTimeOutNs = 10000000;
  const std::string kServiceName = "HumanService";
  DBusStateMachine::HumanCharacterService human_service(kServiceName);
  std::cout << "Server was started, wait for clients...\n";

  usleep(kMainTimeOutNs);
  return 0;
}
