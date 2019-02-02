cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(myvector "")

target_sources(
    myvector
    PRIVATE
        myvector.cpp
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/myvector.h
)

target_include_directories(
    myvector
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)