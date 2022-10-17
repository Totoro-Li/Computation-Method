cmake_minimum_required(VERSION 3.23)
project(ComputationMethod C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(sdk_name ComputationMethod)
set(sdk_sources
        NonlinearEquationsIterative/main.c
        IntegralTransform/fft.c
        ODE/main.c
        Interpolation/LagrangeInterpolation.c)

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
        SHARED
        ${sdk_sources} # c sources (variable 'sdk_sources')
)
target_include_directories(${sdk_name} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

add_custom_command(TARGET ${sdk_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_SHARED_LIBRARY_PREFIX}${sdk_name}.dll
        ${CMAKE_CURRENT_SOURCE_DIR}/../shared_test/sdk/${CMAKE_SHARED_LIBRARY_PREFIX}${sdk_name}.dll

        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${CMAKE_SHARED_LIBRARY_PREFIX}${sdk_name}.lib
        ${CMAKE_CURRENT_SOURCE_DIR}/../shared_test/sdk/${CMAKE_SHARED_LIBRARY_PREFIX}${sdk_name}.lib

        )
add_custom_command(TARGET ${sdk_name} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${PROJECT_SOURCE_DIR}/include/common.h
        ${CMAKE_CURRENT_SOURCE_DIR}/../shared_test/include/common.h
        )
# destination
# e.g. cmake --build . --target install
install(
        TARGETS ${sdk_name}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/out
)