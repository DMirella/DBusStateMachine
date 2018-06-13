#include "human_character_service_client.h"

#include <chrono>
#include <iostream>


namespace DBusStateMachine {
namespace {
const auto kStartMakeConnectionSleepForTime = std::chrono::seconds(5);
const auto kZeroSeconds = std::chrono::seconds(0);
}  // namespace

HumanCharacterServiceClient::HumanCharacterServiceClient(const std::string& service_name) 
    : service_name_(service_name), runtime_(nullptr), service_proxy_(nullptr), status_(Status::CLIENT_NOT_INIT) {
  if (Initialize()) {
    status_ = Status::SERVICE_NOT_AVAILABLE;
  }
  else {
    std::cerr << "Initialization failed!\n";
  }
}

bool HumanCharacterServiceClient::WaitAvailable() {
  if (status_ != Status::SERVICE_NOT_AVAILABLE) {
    std::cerr << "Error in ClientCalculatorDBusService::WaitAvailable(): client not ready\n";
    return false;
  }
  for (auto sleep_time = kStartMakeConnectionSleepForTime; sleep_time > kZeroSeconds; sleep_time /= 2) {
    if (service_proxy_->isAvailable()) {
      status_ = Status::READY_TO_USE;
      break;
    }
    std::cout << "Wait for " << sleep_time.count() << " seconds.\n";
    std::this_thread::sleep_for(sleep_time);
  }
  return status_ == Status::READY_TO_USE;
}

bool HumanCharacterServiceClient::Initialize() {
  runtime_ = CommonAPI::Runtime::get();
  if (runtime_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceClient::Initialize(): runtime_ == nullptr\n";
    return false;
  }
  service_proxy_ 
      = runtime_->buildProxy<v1::com::luxoft::humancharacterservice::HumanCharacterServiceProxy>("", service_name_);
  if (service_proxy_ == nullptr) {
    std::cerr << "Error in HumanCharacterServiceClient::Initialize(): service_proxy_ == nullptr\n";
    return false;
  }
  return true;
}

void HumanCharacterServiceClient::ArmsUp() {
  if (status_ != Status::READY_TO_USE) {
    std::cerr << "Error in HumanCharacterServiceClient::ArmsUp(): client status is not READY_TO_USE\n";
    return;
  }
  CommonAPI::CallStatus status;
  std::string reply;
  service_proxy_->ArmsUp(status, reply);
  std::cout << reply << std::endl;
}

void HumanCharacterServiceClient::ArmsDown() {
  if (status_ != Status::READY_TO_USE) {
    std::cerr << "Error in HumanCharacterServiceClient::ArmsUp(): client status is not READY_TO_USE\n";
    return;
  }
  CommonAPI::CallStatus status;
  std::string reply;
  service_proxy_->ArmsDown(status, reply);
  std::cout << reply << std::endl;
}
}  // DBusStateMachine
