cmake_minimum_required(VERSION 4.1)
project(mis_codigos C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(Cajero_Prog COMB_C/Cajero.c)
add_executable(AppFlash COMB_C/FlashDelivery.c)
add_executable(PROMEDIO COMB_C/PromedioEst.c)
add_executable(Puntero COMB_C/PunterosArreglos.c)