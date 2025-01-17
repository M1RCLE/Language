add_executable(SoSaL main.cpp)

target_link_libraries(SoSaL Language)
target_include_directories(SoSaL PRIVATE ${PROJECT_SOURCE_DIR})