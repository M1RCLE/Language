cmake_minimum_required(VERSION 3.10)

# Укажите проект
project(SoSaL)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 17)

# Укажите путь к установке ANTLR Runtime (с установленными файлами)
set(ANTLR_RUNTIME_DIR "${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime")

# Укажите путь к сгенерированным файлам (например, HelloLexer.h, HelloParser.h)
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/antlr4-runtime/grammer")

# Укажите директории с заголовочными файлами
include_directories(
        ${ANTLR_RUNTIME_DIR}/include/antlr4-runtime       # Путь к заголовочным файлам ANTLR Runtime
        ${SRC_DIR}                                        # Путь к сгенерированным заголовочным файлам
)

# Укажите директорию с библиотеками ANTLR Runtime
link_directories(
        ${ANTLR_RUNTIME_DIR}          # Путь к библиотекам ANTLR Runtime
)

# Укажите исполнимаемый файл (это ваш проект)
add_executable(language_antlr main.cpp)

# Линкуем библиотеку ANTLR Runtime с вашим проектом
target_link_libraries(language_antlr antlr4-runtime)
