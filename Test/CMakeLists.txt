cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(./lib/googletest)

set(gtest_SOURCE_DIR ./lib/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST-SOURCE_FILES RunAllTests.cpp ListaSpesaTest.cpp OggettoTest.cpp UtenteTest.cpp)


add_executable(RunAllTests ${TEST-SOURCE_FILES})
add_executable(RunListaSpesaTest ListaSpesaTest.cpp)
add_executable(RunOggettoTest OggettoTest.cpp)
add_executable(RunUtenteTest UtenteTest.cpp)

target_link_libraries(RunListaSpesaTest gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(RunOggettoTest gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(RunUtenteTest gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)
target_link_libraries(RunAllTests gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)