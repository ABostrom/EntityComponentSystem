# CMakeList.txt : CMake project for EntityComponentSystem, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (EntityComponentSystem)

# Add source to this project's executable.
# Automatically find all source files in the src directory
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCES "src/*.cpp")

# Add the executable
add_executable(EntityComponentsystemBuild "EntityComponentSystem.h" "EntityComponentSystem.cpp"  ${HEADER_FILES} ${SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EntityComponentsystemBuild PROPERTY CXX_STANDARD 20)
endif()


target_include_directories(EntityComponentsystemBuild PUBLIC "${PROJECT_SOURCE_DIR}/include")
