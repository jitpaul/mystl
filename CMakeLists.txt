cmake_minimum_required(VERSION 3.5)

project(mystl CXX)

#Source
add_subdirectory(src)

#Test
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(DownloadProject)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
                 QUIET
)
add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
enable_testing()
add_subdirectory(test)