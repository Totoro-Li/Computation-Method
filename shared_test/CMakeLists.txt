cmake_minimum_required(VERSION 3.23)
project(test_shared C)

set(CMAKE_C_STANDARD 99)

find_library(sdk_shared ComputationMethod ./sdk)
