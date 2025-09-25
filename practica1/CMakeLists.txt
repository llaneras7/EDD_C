# set cmake minimum required version
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# define a c project with name provided as parameter (cmake CMakeLists.txt -DPRJCT_NAME=foo)
project(Practica1 C)

# enable compilation warnings
add_compile_options(-std=c17 -Wall -Wextra -Wpedantic)

add_executable(mainTask src/MainTask.c src/Task.c)


