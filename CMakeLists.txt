cmake_minimum_required(VERSION 3.9)
project(mylib VERSION 1.0.0 DESCRIPTION "mylib description")


add_library(mylib SHARED
     SharedSrc.c
)

set_target_properties(mylib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(mylib PROPERTIES SOVERSION 1)

#set_target_properties(mylib PROPERTIES PUBLIC_HEADER include/mylib.h)

target_include_directories(mylib PRIVATE .)


