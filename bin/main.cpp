#include <sstream>
#include <chrono>

#include "lib/lib.h"

int main(int argc, char *argv[]) {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    try {
        std::ifstream file(filename);
        if (!file) {
            throw std::ios_base::failure("Error reading file");
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        std::string code = buffer.str();

        Lexer lexer(code);
        std::vector<Token> tokens = lexer.tokenize();

        Parser parser(tokens);
        std::vector<Instruction> instructions = parser.parse();

        Compiler compiler(instructions);
        std::string compiledFile =
                filename.substr(0, filename.find_last_of('.')) + ".bytecel";
        compiler.saveToFile(compiledFile);

        VirtualMachine vm;
        vm.loadFromFile(compiledFile);
        vm.run();

    } catch (const std::ios_base::failure &e) {
        std::cerr << "Error reading or writing file: " << e.what() << std::endl;
        return 2;
    } catch (const std::exception &e) {
        std::cerr << "Error executing program: " << e.what() << std::endl;
        return 3;
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count()
              << std::endl;

    return 0;
}