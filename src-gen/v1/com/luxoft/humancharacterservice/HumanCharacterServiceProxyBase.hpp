/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.12.v201801251447.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COM_LUXOFT_HUMANCHARACTERSERVICE_Human_Character_Service_PROXY_BASE_HPP_
#define V1_COM_LUXOFT_HUMANCHARACTERSERVICE_Human_Character_Service_PROXY_BASE_HPP_

#include <v1/com/luxoft/humancharacterservice/HumanCharacterService.hpp>



#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/InputStream.hpp>
#include <CommonAPI/OutputStream.hpp>
#include <cstdint>
#include <vector>

#include <CommonAPI/Proxy.hpp>
#include <functional>
#include <future>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace com {
namespace luxoft {
namespace humancharacterservice {

class HumanCharacterServiceProxyBase
    : virtual public CommonAPI::Proxy {
public:

    typedef std::function<void(const CommonAPI::CallStatus&, const std::string&)> ArmUpAsyncCallback;
    typedef std::function<void(const CommonAPI::CallStatus&, const std::string&)> ArmDownAsyncCallback;



    virtual void ArmUp(const HumanCharacterService::Arm &_arm, CommonAPI::CallStatus &_internalCallStatus, std::string &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> ArmUpAsync(const HumanCharacterService::Arm &_arm, ArmUpAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual void ArmDown(const HumanCharacterService::Arm &_arm, CommonAPI::CallStatus &_internalCallStatus, std::string &_result, const CommonAPI::CallInfo *_info = nullptr) = 0;
    virtual std::future<CommonAPI::CallStatus> ArmDownAsync(const HumanCharacterService::Arm &_arm, ArmDownAsyncCallback _callback = nullptr, const CommonAPI::CallInfo *_info = nullptr) = 0;
};

} // namespace humancharacterservice
} // namespace luxoft
} // namespace com
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COM_LUXOFT_HUMANCHARACTERSERVICE_Human_Character_Service_PROXY_BASE_HPP_
