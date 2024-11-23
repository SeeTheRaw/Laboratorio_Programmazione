cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest)

set(gtest_SOURCE_DIR, ./lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST-SOURCE_FILES
        
        OggettoTest.cpp
)

add_executable(runProgettoTest ${TEST-SOURCE_FILES})

target_link_libraries(runProgettoTest gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)