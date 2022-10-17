cmake_minimum_required(VERSION 3.23)
project(test_shared C)

set(CMAKE_C_STANDARD 99)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

find_library(sdk_shared ComputationMethod ./sdk)

set(source main.c)
set(header ./include)

add_executable(test_shared ${source})
add_custom_command(TARGET test_shared POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/sdk ${PROJECT_SOURCE_DIR}/bin
        )
target_include_directories(test_shared PUBLIC ${header})
target_link_libraries(test_shared ${sdk_shared})