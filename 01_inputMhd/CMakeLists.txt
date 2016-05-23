cmake_minimum_required(VERSION 2.8)
project(01_inputMhd)

## Check for Windows ##
if (WIN32) # true if windows (32 and 64 bit)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif ()





set(CMAKE_BUILD_TYPE Release)
set(VTK_DIR /usr/local/vtk/bin)
set(ITK_DIR /usr/local/itk/bin)


find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
find_package(ITK REQUIRED)
FIND_PACKAGE(GSL REQUIRED)
include(${ITK_USE_FILE})



set(SOURCE_FILES main.cpp)
add_executable(01_inputMhd ${SOURCE_FILES})

target_link_libraries( 01_inputMhd ${VTK_LIBRARIES} ${ITK_LIBRARIES} ${ROOT_LIBRARIES} ${GSL_LIBRARIES})