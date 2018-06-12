#include <unistd.h>

#include <ctime>
#include <string>

#include "human_character_service_client.h"


int main(){
  srand(time(0));

  const std::string kServiceName = "HumanService";
  const int kMaxCountTryToConnect = 5;
  const int kTimeoutSleepForTimeNs = 100000;
   
  DBusStateMachine::HumanCharacterServiceClient service_client(kServiceName);

  bool service_available = false;
  for (int current_try = 1; current_try <= kMaxCountTryToConnect; ++current_try) {
    if (service_client.WaitAvailable()) {
      service_available = true;
      break;
    }
  }
  if (!service_available) {
    std::cerr << "Service connection failed!\n";
    return 0;
  }
  
  std::cout << "Service was found, start to work...\n";
  while (true) {
    DBusStateMachine::HumanCharacterServiceClient::Arm arm 
        = static_cast<DBusStateMachine::HumanCharacterServiceClient::Arm>(rand() % 2);
    switch (rand() % 2) {
     case 0:
      std::cout << "Try to moving up " 
          << ((arm == DBusStateMachine::HumanCharacterServiceClient::Arm::LEFT)? "left" : "right")
          << " arm\n";
      service_client.ArmUp(arm);
      break;
     case 1:
      std::cout << "Try to moving down " 
          << ((arm == DBusStateMachine::HumanCharacterServiceClient::Arm::LEFT)? "left" : "right")
          << " arm\n";
      service_client.ArmDown(arm);
      break;
    }
    usleep(kTimeoutSleepForTimeNs);
  }
  
  return 0;
}
