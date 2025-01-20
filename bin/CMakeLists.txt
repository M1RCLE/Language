add_executable(CEL main.cpp)

target_link_libraries(CEL Language)
target_include_directories(CEL PRIVATE ${PROJECT_SOURCE_DIR})