cmake_minimum_required(VERSION 3.23)
project(ComputationMethod C)

set(CMAKE_C_STANDARD 99)

set(sdk_name ComputationMethod)
set(sdk_sources
        NonlinearEquationsIterative/main.c
        IntegralTransform/fft.c
        ODE/main.c)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_TESTS "Build tests" ON)
# Project Info
project(
        ${sdk_name} # projectName
        VERSION 0.0.1 # [VERSION major[.minor[.patch[.tweak]]]]
        LANGUAGES C CXX # [LANGUAGES languageName ...]
)

add_library(
        ${sdk_name} # create a target as a library

        # SHARED/STATIC         # ignore library type because it will be decided by 'BUILD_SHARED_LIBS'
        ${sdk_sources} # c sources (variable 'sdk_sources')
)
target_include_directories(${sdk_name} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )
# destination
# e.g. cmake --build . --target install
install(
        TARGETS ${sdk_name}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/out
)