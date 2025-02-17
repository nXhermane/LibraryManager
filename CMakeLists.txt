cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# add includes directories to the project and access to relative path 
include_directories(includes)

# list all source file 
file(GLOB SOURCE_FILE "./src/*.cpp")

# define a project name
project(LIBRARY_MANAGER)

# add executable to the project 
add_executable(LIBRARY_MANAGER ${SOURCE_FILE})

# add custom target to execute a command 
add_custom_target(
    run COMMAND LIBRARY_MANAGER WORKING_DIRECTORY "./"
)

add_custom_target(run_watch COMMAND nodemon --watch "./src/*" --exec "cmake --build ./build --target run" --ext cpp WORKING_DIRECTORY "..")