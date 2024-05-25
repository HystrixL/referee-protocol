cmake_minimum_required(VERSION 3.5)
project(referee_protocol LANGUAGES CXX)

add_library(${PROJECT_NAME} OBJECT ./referee_protocol.hpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})
