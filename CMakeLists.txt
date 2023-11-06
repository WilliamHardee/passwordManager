cmake_minimum_required(VERSION 3.28.0)
project(manager)


add_executable(manager src/Account.cpp src/driver.cpp)
target_include_directories(manager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)