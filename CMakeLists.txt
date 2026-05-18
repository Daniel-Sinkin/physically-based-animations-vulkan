cmake_minimum_required(VERSION 3.20)

if(APPLE AND NOT DEFINED CMAKE_C_COMPILER AND NOT DEFINED CMAKE_CXX_COMPILER)
  foreach(PBA_LLVM_PREFIX IN ITEMS /opt/homebrew/opt/llvm /usr/local/opt/llvm)
    if(EXISTS "${PBA_LLVM_PREFIX}/bin/clang" AND EXISTS "${PBA_LLVM_PREFIX}/bin/clang++")
      set(CMAKE_C_COMPILER "${PBA_LLVM_PREFIX}/bin/clang" CACHE FILEPATH "C compiler" FORCE)
      set(CMAKE_CXX_COMPILER "${PBA_LLVM_PREFIX}/bin/clang++" CACHE FILEPATH "C++ compiler" FORCE)
      message(STATUS "Using LLVM toolchain from ${PBA_LLVM_PREFIX}")
      break()
    endif()
  endforeach()
endif()

project(physically_based_animations_vulkan LANGUAGES C CXX)

if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(external/ds-vk)

if(NOT TARGET ds_vk)
  message(FATAL_ERROR "ds_vk runtime target is unavailable. Install Vulkan and glslc, or configure ds-vk runtime support.")
endif()

add_executable(physically_based_animations_vulkan
  app/main.cpp
  src/pba/physics.cpp
)
target_include_directories(physically_based_animations_vulkan PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_precompile_headers(physically_based_animations_vulkan PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pch.hpp
)
target_compile_definitions(physically_based_animations_vulkan PRIVATE
  DS_VK_ASSET_DIR="${CMAKE_CURRENT_SOURCE_DIR}/local/assets"
)
target_link_libraries(physically_based_animations_vulkan PRIVATE
  ds_vk
  ds_vk_viz
  ds_vk_picker
  ds_vk_manipulator
  ds_vk_warnings
)
