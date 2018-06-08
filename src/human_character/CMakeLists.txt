cmake_minimum_required(VERSION 2.6)
project(HumanCharacterService)

set(SERVICE_SRCGEN            /home/dima/work/DBusStateMachine/src-gen)
set(SRCGEN_V1_COM_LUXOFT_PATH ${SERVICE_SRCGEN}/v1/com/luxoft/humancharacterservice)
set(SERVICE_SRCGEN_CCPS       ${SRCGEN_V1_COM_LUXOFT_PATH}/HumanCharacterServiceDBusDeployment.cpp
		              ${SRCGEN_V1_COM_LUXOFT_PATH}/HumanCharacterServiceDBusStubAdapter.cpp
			      ${SRCGEN_V1_COM_LUXOFT_PATH}/HumanCharacterServiceStubDefault.cpp)
file(GLOB CC_FILES *.cc)
include(/home/dima/work/DBusStateMachine/src/cmake_includes/DBusSets.txt)
include_directories(${SERVICE_SRCGEN}
		    ${DBUS_INCLUDE_DIRECTORIES})
link_directories(${DBUS_LINK_DIRECTORIES})

add_executable(HumanCharacterService ${CC_FILES} ${SERVICE_SRCGEN_CCPS})
target_link_libraries(HumanCharacterService ${DBUS_LIBS})
