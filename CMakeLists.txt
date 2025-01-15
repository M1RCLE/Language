cmake_minimum_required(VERSION 3.10)

# Project name
project(SoSaL)

# C++ standard
set(CMAKE_CXX_STANDARD 17)

# Path to ANTLR Runtime
set(ANTLR_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/antlr4-gen")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/grammer")
set(ANTLR_RUNTIME_LIB_DIR "${ANTLR_RUNTIME_DIR}/lib")

# Include directories
include_directories(
        ${ANTLR_RUNTIME_DIR}/include/antlr4-runtime   # ANTLR runtime headers
        ${SRC_DIR}                                   # Generated headers
)

# Add all generated source files for lexer and parser
set(GENERATED_SOURCES
        ${SRC_DIR}/MyLanguageLexer.cpp
        ${SRC_DIR}/MyLanguageParser.cpp
        ${SRC_DIR}/MyLanguageBaseListener.cpp  # Add other files as needed
)

# Add executable
add_executable(language_antlr main.cpp ${GENERATED_SOURCES})

# Link ANTLR runtime library
target_link_libraries(language_antlr ${ANTLR_RUNTIME_LIB_DIR}/libantlr4-runtime.a)

# Set RPATH for runtime library
set(CMAKE_BUILD_RPATH "${ANTLR_RUNTIME_LIB_DIR}")
