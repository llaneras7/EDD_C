cmake_minimum_required(VERSION 3.20)
project(lista-enlazada)
add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)  # Para todo el proyecto

add_executable(principal listaEnlazada.c principal.c)

#si solo quiere añadir a este ejecutable y sus dependientes
#target_compile_options(principal PUBLIC -Wall -Wextra)