// ANTLR Setup in C++

#include <iostream>
#include "antlr4-runtime.h"  // Include the ANTLR runtime for C++
#include "MyLanguageLexer.h"  // Include the generated lexer header
#include "MyLanguageParser.h"  // Include the generated parser header

using namespace antlr4;

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <source-file>\n";
        return 1;
    }

    const std::string sourceFile = argv[1];

    try {
        // Open the input file
        std::ifstream stream;
        stream.open(sourceFile);
        if (!stream.is_open()) {
            std::cerr << "Failed to open file: " << sourceFile << "\n";
            return 1;
        }

        // Create ANTLR input stream
        ANTLRInputStream input(stream);

        // Create the lexer
        MyLanguageLexer lexer(&input);

        // Create a token stream from the lexer
        CommonTokenStream tokens(&lexer);

        // Create the parser
        MyLanguageParser parser(&tokens);

        // Parse the input and obtain the parse tree
        MyLanguageParser::ProgramContext* tree = parser.program();  // Replace "program" with your root rule

        // Print the parse tree (for debugging purposes)
        std::cout << "Parse tree: " << tree->toStringTree(&parser) << "\n";

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
