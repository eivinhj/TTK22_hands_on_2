cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
# Project name
project(imc_cpp)
# Where to find included source files
include_directories("${PROJECT_SOURCE_DIR}")
# List sources related with CPP IMC bindings
file(GLOB_RECURSE IMC_SOURCES "${PROJECT_SOURCE_DIR}/IMC/*.cpp")
file(GLOB_RECURSE IMC_HEADERS "${PROJECT_SOURCE_DIR}/IMC/*.hpp")
# Create a (static by default) library using all of IMC sources


# Source files in source directory
set(SOURCE
    ${PROJECT_SOURCE_DIR}/main.cpp 
    ${IMC_SOURCES}
  )
  set(HEADERS
  ${IMC__HEADERS}
)

# Create a (static by default) library using all of IMC sources / headers
add_library(imc ${IMC__HEADERS} ${IMC_SOURCES})

add_executable(main ${SOURCE} ${HEADERS})