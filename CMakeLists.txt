project("othello-project-sohinithota")

cmake_minimum_required(VERSION 2.6)

# https://stackoverflow.com/questions/6594796/how-do-i-make-cmake-output-into-a-bin-dir
# We only need 'bin' here.

if (CMAKE_VERSION VERSION_LESS "3.1")
  add_definitions(-std=c++11)
else()
  set(CMAKE_CXX_STANDARD 11)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})



add_executable(othello_demo othello_demo.c othello.c )
target_link_libraries(othello_demo -lm)

add_executable(othello_tests othello_tests.cc othello.c)
target_link_libraries(othello_tests ${GTEST_LIBRARIES} -lpthread -lm)
