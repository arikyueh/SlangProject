//------------------------------------------------------------------------------
// rewriter.cpp
// Simple tool that parses an input file and writes it back out; used
// for verifying the round-trip nature of the parse tree.
//
// File is under the MIT license; see LICENSE for details
//------------------------------------------------------------------------------

#include <cstdio>
#if defined(_WIN32)
#    include <fcntl.h>
#    include <io.h>
#endif

#include <filesystem>
#include <iostream>
#include "slang/syntax/SyntaxPrinter.h"
#include "slang/syntax/SyntaxTree.h"
#include "slang/compilation/Compilation.h"
#include "slang/symbols/CompilationUnitSymbols.h"
#include <slang/symbols/ParameterSymbols.h>
#include "slang/parsing/Token.h"
#include "slang/util/SmallVector.h"
#include <slang/parsing/Lexer.h>
#include "slang/parsing/Preprocessor.h"
using namespace slang;
using namespace std;

int main(int argc, char** argv) try {
    if (argc != 2) {
        fprintf(stderr, "usage: rewriter file\n");
        return 1;
    }

    // Make sure we reproduce newlines correctly on Windows:
#if defined(_WIN32)
    _setmode(_fileno(stdout), _O_BINARY);
#endif

    if (!std::filesystem::exists(argv[1])) {
        fprintf(stderr, "File does not exist: %s\n", argv[1]);
        return 1;
    }

    if (!std::filesystem::is_regular_file(argv[1])) {
        fprintf(stderr, "%s is not a file\n", argv[1]);
        return 1;
    }
    Compilation compilation;
    
    auto tree = SyntaxTree::fromFile(argv[1]);
    auto m=&tree->sourceManager();

    compilation.addSyntaxTree(tree);
    auto varEnd=tree->root().getLastToken();
    auto varStart=tree->root().getFirstToken();
    //Preprocessor &P;
    //varToken.trivia()
    //Token varToken;
    //auto alloc=P.getAllocator();
    //varToken = Lexer::stringify(alloc, varStart.location(), varStart.trivia(),
    //               varStart, varEnd);


    cout << "token:" << varStart.valueText() <<endl;

    // while(i<childcount){
    //     auto varToken = tree->root().childToken(i);
    //     
    //     i++;
    // }
        

    //auto child=tree->root().childNode
    //auto next=tree->root().;
    //const auto& module = *compilation.getRoot().topInstances[0];
    //const ParameterSymbol& param = module.body.memberAt<ParameterSymbol>(0);
   
    
    //cout << "last token:" << next.toString() <<endl;
    //printf("Token: %s\n",&varToken.toString());     
    //while(*(varToken.toString())='\0')
        //printf("%c",*(varToken.toString())++);
    //printf("Module: %d\n",param.getValue().integer();));
    printf("%s", SyntaxPrinter::printFile(*tree).c_str());
    return 0;
}
catch (const std::exception& e) {
    printf("internal compiler error (exception): %s\n", e.what());
    return 2;
}