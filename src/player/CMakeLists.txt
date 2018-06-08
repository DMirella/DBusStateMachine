cmake_minimum_required(VERSION 2.6)
project(Player)

set(SERVICE_SRCGEN_PATH   	     /home/dima/work/DBusStateMachine/src-gen)
set(SRCGEN_V1_COM_LUXOFT_PATH        ${SERVICE_SRCGEN_PATH}/v1/com/luxoft/humancharacterservice)
set(SRCGEN_V1_COM_LUXOFT_PATH_CPPS   ${SERVICE_SRCGEN_PATH}/v1/com/luxoft/humancharacterservice)
set(SRCGEN_V1_COM_LUXOFT_CLIENT_CPPS ${SRCGEN_V1_COM_LUXOFT_PATH}/HumanCharacterServiceDBusDeployment.cpp
		      		     ${SRCGEN_V1_COM_LUXOFT_PATH}/HumanCharacterServiceDBusProxy.cpp)
file(GLOB CC_FILES *.cc)
include(/home/dima/work/DBusStateMachine/src/cmake_includes/DBusSets.txt)
include_directories(${SERVICE_SRCGEN_PATH}
	 	    ${DBUS_INCLUDE_DIRECTORIES})
link_directories(${DBUS_LINK_DIRECTORIES})

add_executable(Player ${CC_FILES} ${SRCGEN_V1_COM_LUXOFT_CLIENT_CPPS})
target_link_libraries(Player ${DBUS_LIBS})
