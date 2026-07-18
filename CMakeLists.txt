cmake_minimum_required(VERSION 3.15)
project(EyeTrackingCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(EyeTrackingCore ${SOURCES})

target_include_directories(EyeTrackingCore PRIVATE include ${OpenCV_INCLUDE_DIRS})
target_link_libraries(EyeTrackingCore PRIVATE ${OpenCV_LIBS})