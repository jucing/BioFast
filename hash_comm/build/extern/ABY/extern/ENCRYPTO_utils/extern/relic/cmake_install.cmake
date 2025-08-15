# Install script for directory: /home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/relic" TYPE FILE FILES
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_alloc.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_arch.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_bc.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_bench.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_bn.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_core.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_cp.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_dv.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_eb.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_ec.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_ed.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_ep.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_epx.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_err.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_fb.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_fbx.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_fp.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_fpx.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_label.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_md.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_mpc.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_multi.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_pc.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_pp.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_rand.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_test.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_types.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/relic_util.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/relic/low" TYPE FILE FILES
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/low/relic_bn_low.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/low/relic_dv_low.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/low/relic_fb_low.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/low/relic_fp_low.h"
    "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/low/relic_fpx_low.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/relic" TYPE DIRECTORY FILES "/home/jucing/BIoFast/hash_comm/build/extern/ABY/extern/ENCRYPTO_utils/extern/relic/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "/home/jucing/BIoFast/hash_comm/extern/ABY/extern/ENCRYPTO_utils/extern/relic/cmake/relic-config.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/jucing/BIoFast/hash_comm/build/extern/ABY/extern/ENCRYPTO_utils/extern/relic/src/cmake_install.cmake")

endif()

