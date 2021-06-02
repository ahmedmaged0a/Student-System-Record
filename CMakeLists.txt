cmake_minimum_required(VERSION 3.17)
project(Cpt_Maged C)

set(CMAKE_C_STANDARD 90)

add_executable(Cpt_Maged main.c privileges.c privileges.h interface.c interface.h List.c List.h)