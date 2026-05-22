cmake_minimum_required(VERSION 3.20)
project(project LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT TARGET zstd::libzstd_static)
    add_library(zstd::libzstd_static INTERFACE IMPORTED)
endif()

set(LLVM_DIR "/home/shevo/LLVM-22.1.0-Linux-X64/lib/cmake/llvm")
set(MLIR_DIR "/home/shevo/LLVM-22.1.0-Linux-X64/lib/cmake/mlir")

find_package(LLVM REQUIRED CONFIG)
find_package(MLIR REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS} ${MLIR_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

add_executable(mlir-driver src/main.cpp)

# ... (rest of CMake remains identical)

target_link_libraries(mlir-driver PRIVATE
    MLIRIR
    MLIRParser
    MLIRSupport
    MLIRFuncDialect
    MLIRArithDialect # <-- Add this linker target
)

