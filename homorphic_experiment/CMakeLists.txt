cmake_minimum_required(VERSION 3.12)
project(homorphic_experiment VERSION 1.0)
#add_compile_options(-std=c++17)
#add_compile_options(-std=c++17 -Wall -Wextra -Wpedantic)

### To use gcc/g++ on a Macintosh, you must set the Compilers
### here, not inside the project
##if(APPLE)
##       set(CMAKE_C_COMPILER "/usr/local/bin/gcc-7")
##       set(CMAKE_CXX_COMPILER "/usr/local/bin/g++-7")
##endif()
### TODO: for now, we use CLang for Mac
###
### In order to create OpenFHE's static libraries you should enable
### the BUILD_STATIC option. For that, you run "cmake .. -DBUILD_STATIC=ON".
### After having your link completed you will find static libs
### with the suffix "_static" in ./build/libs/.
### Examples: OPENFHEpke_static.a, OPENFHEcore_static.a, etc.
### After you run "make install" in your build directory, you can build your custom application.
### If you need your application to be linked statically, then run "cmake .. -DBUILD_STATIC=ON"

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

option( BUILD_STATIC "Set to ON to include static versions of the library" OFF)




# find_package(ABY QUIET)
if(ABY_FOUND)
    message(STATUS "Found ABY")
elseif (NOT ABY_FOUND AND NOT TARGET ABY::aby)
    message("ABY was not found: add ABY subdirectory")
    add_subdirectory(extern/ABY)
endif()

# Import Microsoft SEAL
find_package(SEAL 4.1.2 EXACT REQUIRED)



# add_executable(adddemo open.cpp common/millionaire_prob.cpp)
add_executable(adddemo open.cpp )
add_executable(readData readData.cpp )


if(SEAL_FOUND)
    message("SEAL Found")
    include_directories(${SEAL_INCLUDE_DIRS}, "include/")
    target_link_libraries(adddemo SEAL::seal)
     target_link_libraries(readData SEAL::seal)
   
    
elseif(NOT SEAL_FOUND)
    error("SEAL Not Found")
endif()



target_link_libraries(adddemo  ABY::aby ENCRYPTO_utils::encrypto_utils)
target_link_libraries(readData  ABY::aby ENCRYPTO_utils::encrypto_utils)









