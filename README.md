# Social Safe Language (SoSaL)

## Примечание

В связи с тем, что директория `antlr` не подгружается на github, нужно выполнить следующие шаги:
1. Склонировать этот проект к себе.
2. git clone https://github.com/antlr/antlr4.git
3. - mkdir build 
   - cd build
   - cmake .. -DCMAKE_INSTALL_PREFIX=~/Language/antlr4/runtime/Cpp/build/antlr4-runtime
   - make
   - make install
4. Далее внутри `antlr4-runtime` создать директорию `grammer` и добавить туда файл `MyLanguage.g4` (он находится в корне проекта).
5. После выполнить `java -jar antlr-<version>-complete.jar -Dlanguage=Cpp ~/Language/antlr4/runtime/Cpp/build/antlr4-runtime/grammer/MyLanguage.g4`
6. Запустить файл `main.cpp` и в аргументах указать полный путь к файлу `example.ssl`