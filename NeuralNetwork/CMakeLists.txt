# Specify the minimum version of cmake
cmake_minimum_required(VERSION 3.5)
# Name of the project for now:
project(NeuralNetwork)

# Setting a sources variable with all the links to cpp files to compile
set(SOURCES src/main.cpp)

# Adding an executable with name EigenLibraryTest 
# and sources defined in the source varibale
add_executable(NeuralNetwork ${SOURCES})

# Now I set the directories that should be included during the build command for this target

set_property(TARGET NeuralNetwork PROPERTY CXX_STANDARD 14)
target_include_directories(NeuralNetwork
   PRIVATE
        ${PROJECT_SOURCE_DIR}/include

)