project(json)

cmake_minimum_required(VERSION 3.18)

set(CMAKE_EXPORT_COMPILE_COMMANDS True)

find_package(Threads REQUIRED COMPONENTS Threads)

link_libraries(Threads::Threads)

enable_testing()




add_library(
    json_lib
)

target_sources(
    json_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Album.hpp
           ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Band.cpp
           ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Band.hpp
           ${CMAKE_CURRENT_SOURCE_DIR}/src/lib/Member.hpp
)

find_package(Boost REQUIRED COMPONENTS json)

target_include_directories(
    json_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/lib
)

target_link_libraries(
    json_lib
    PUBLIC Boost::json
)




add_executable(
    json_test
)

target_sources(
    json_test
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/test/BandTest.cpp
)

find_package(GTest REQUIRED COMPONENTS gtest gtest_main)

target_link_libraries(
    json_test
    PRIVATE json_lib
            gtest
            gtest_main
)

add_test(
  NAME json_test
  COMMAND json_test
)
