set(assemble_tgz OFF)

cmake_minimum_required(VERSION 3.31)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib/shared)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/lib/static)

project(fifteen VERSION 1.0.0 LANGUAGES CXX)

add_library(data_gen SHARED ${CMAKE_SOURCE_DIR}/lib/data_gen.cpp)
target_include_directories(data_gen PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(keys SHARED ${CMAKE_SOURCE_DIR}/lib/keys.cpp)
target_include_directories(keys PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(mswap SHARED ${CMAKE_SOURCE_DIR}/lib/m_swap.cpp)
target_include_directories(mswap PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_library(print SHARED ${CMAKE_SOURCE_DIR}/lib/print.cpp)
target_include_directories(print PUBLIC ${CMAKE_SOURCE_DIR}/include)

# add_library(one STATIC ${CMAKE_SOURCE_DIR}/lib/*.cpp)
# target_include_directories(one PUBLIC ${CMAKE_SOURCE_DIR}/include)

# add_library(two SHARED ${CMAKE_SOURCE_DIR}/lib/*.cpp)
# target_include_directories(two PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE data_gen keys mswap print)

# target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
# target_link_libraries(${PROJECT_NAME} PRIVATE one)
# target_link_libraries(${PROJECT_NAME} PRIVATE two)

# install(DIRECTORY path/to/extra/files/ DESTINATION share/fifteen/extra)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(TARGETS data_gen keys mswap print LIBRARY DESTINATION lib)

if(assemble_tgz)
    install(FILES ${CMAKE_SOURCE_DIR}/sources/fifteen DESTINATION "."
                        PERMISSIONS
                        OWNER_READ OWNER_WRITE OWNER_EXECUTE
                        GROUP_READ GROUP_EXECUTE 
                        WORLD_READ WORLD_EXECUTE)
endif()

set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "puzzle fifteen for Linux terminal")

if(assemble_tgz)
    set(CPACK_GENERATOR "TGZ")
else()
    set(CPACK_GENERATOR "RPM")
    set(CPACK_RPM_PACKAGE_RELOCATABLE "TRUE")
endif()

include(CPack)
