cmake_minimum_required(VERSION 3.5)

add_executable(
    unit_tests
    myvector.t.cpp
)

target_link_libraries(
    unit_tests
    gtest_main
    myvector
)

add_test(
  NAME
    unit
  COMMAND
    ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)
