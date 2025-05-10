cmake_minimum_required(VERSION 3.31)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_BINARY_DIR app)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/static)

project(fifteen LANGUAGES CXX)

set(SRC src/main.cpp)
add_library(data_gen STATIC include/data_gen.h lib/data_gen.cpp)
add_library(keys STATIC include/keys.h lib/keys.cpp)
add_library(mswap STATIC include/m_swap.h lib/m_swap.cpp)
add_library(print STATIC include/print.h lib/print.cpp)

#add_library(one STATIC lib/*.h lib/*.cpp)
#add_library(two SHARED lib/*.h lib/*.cpp)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} data_gen)
target_link_libraries(${CMAKE_PROJECT_NAME} keys)
target_link_libraries(${CMAKE_PROJECT_NAME} mswap)
target_link_libraries(${CMAKE_PROJECT_NAME} print)

#target_link_libraries(${CMAKE_PROJECT_NAME} one)
#target_link_libraries(${CMAKE_PROJECT_NAME} two)
