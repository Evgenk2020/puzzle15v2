cmake_minimum_required(VERSION 3.31)
project(fifteen VERSION 2.0.2 LANGUAGES CXX)

# -------------------------------------------------------------
# to switch packaging to *.tar.gz >>> set(assemble_tgz ON)
set(assemble_tgz OFF)
# -------------------------------------------------------------

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

add_library(pzl_data_gen SHARED ${CMAKE_SOURCE_DIR}/lib/data_gen.cpp)
add_library(pzl_keys SHARED ${CMAKE_SOURCE_DIR}/lib/keys.cpp)
add_library(pzl_mswap SHARED ${CMAKE_SOURCE_DIR}/lib/m_swap.cpp)
add_library(pzl_print SHARED ${CMAKE_SOURCE_DIR}/lib/print.cpp)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE pzl_data_gen pzl_keys pzl_mswap pzl_print)
# file(COPY ${CMAKE_SOURCE_DIR}/sources/fifteen DESTINATION ${CMAKE_BINARY_DIR})

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS pzl_data_gen pzl_keys pzl_mswap pzl_print LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

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
