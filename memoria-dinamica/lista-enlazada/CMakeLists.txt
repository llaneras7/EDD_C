cmake_minimum_required(VERSION 3.20)
project(memoria_dinamica)
add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)  # Para todo el proyecto

add_executable(listaEnlazada listaEnlazada.c)

#si solo quiere añadir a este ejecutable y sus dependientes
#target_compile_options(principal PUBLIC -Wall -Wextra)