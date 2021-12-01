set(PROJECT_NAME VoxelMap)

cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release) 
endif()

message("Build type: " ${CMAKE_BUILD_TYPE})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
LIST(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(PCL REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/VoxelMap.cpp)

add_executable(voxel_test ${PROJECT_SOURCE_DIR}/voxel_test.cpp)
target_link_libraries(voxel_test PUBLIC ${PCL_LIBRARIES}
                                        ${PROJECT_NAME})