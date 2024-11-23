cmake_minimum_required(VERSION 3.29)
project(ProgettoLaboratorio)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(Test)

set(SOURCE-FILES
        main.cpp
        ListaSpesa.cpp
        ListaSpesa.h
        Oggetto.h
        Utente.h
        Subject.h
        Observer.h
)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE-FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)
