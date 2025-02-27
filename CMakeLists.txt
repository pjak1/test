cmake_minimum_required(VERSION 3.10.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

add_executable(test src/main.cpp src/KeyLogger.cpp src/KeyboardListenerWindows.cpp)

target_include_directories(test PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(test PRIVATE ws2_32 advapi32)

