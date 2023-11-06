cmake_minimum_required(VERSION 3.28.0)
project(manager)


add_executable(manager src/Account.cpp src/driver.cpp)
target_include_directories(manager PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(manager PRIVATE "C:\\Program Files\\libpqxx\\include")
target_link_libraries(manager PRIVATE "C:\\Program Files\\libpqxx\\lib\\pqxx.lib")
find_package(libpqxx REQUIRED)

target_link_libraries(manager PRIVATE "C:\\Program Files\\PostgreSQL\\16\\lib\\libpq.lib")
target_include_directories(manager PRIVATE "C:\\Program Files\\PostgreSQL\\16\\include")

set_property(TARGET manager PROPERTY CXX_STANDARD 17)