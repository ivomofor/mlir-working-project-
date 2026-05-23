cmake_minimum_required(VERSION 3.20)

project(project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ------------------------------------------------------------------------------
# LLVM / MLIR paths
# ------------------------------------------------------------------------------

set(LLVM_DIR "/home/shevo/LLVM-22.1.0-Linux-X64/lib/cmake/llvm")
set(MLIR_DIR "/home/shevo/LLVM-22.1.0-Linux-X64/lib/cmake/mlir")

find_package(LLVM REQUIRED CONFIG)
find_package(MLIR REQUIRED CONFIG)

message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")

# ------------------------------------------------------------------------------
# IMPORTANT: MATCH LLVM RTTI SETTINGS
# ------------------------------------------------------------------------------

add_compile_options(-fno-rtti)

# ------------------------------------------------------------------------------
# Include directories
# ------------------------------------------------------------------------------

include_directories(
  ${LLVM_INCLUDE_DIRS}
  ${MLIR_INCLUDE_DIRS}
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

link_directories(${LLVM_LIBRARY_DIRS})

add_definitions(${LLVM_DEFINITIONS})

# ------------------------------------------------------------------------------
# Executable
# ------------------------------------------------------------------------------

add_executable(mlir-driver
  src/main.cpp
  src/MyDialect.cpp
)

# ------------------------------------------------------------------------------
# MLIR libraries
# ------------------------------------------------------------------------------

target_link_libraries(mlir-driver PRIVATE
  MLIRIR
  MLIRParser
  MLIRSupport
  MLIRFuncDialect
  MLIRArithDialect
)