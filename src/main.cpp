#include <iostream>
#include <fstream>

#include "ast/ast.hpp"
#include "sema/type_checker.hpp"
using namespace kompis;

#include "parser.hpp"

int yyparse();

extern ast::ProgramDeclaration *program_declaration;

std::ostream *ast_stream = NULL;
std::ostream *irt_stream = NULL;
std::ostream *out_stream = NULL;

int main(int argc, char *argv[])
{
  int opt;
  while((opt = getopt(argc, argv, "Aa:Ii:o:")) != -1)
  {
    switch(opt)
    {
      case 'A': // print AST to stdout (default none)
        ast_stream = &std::cout;
        break;
      case 'a': // print AST to file:
        ast_stream = new std::ofstream(optarg, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
        break;
      case 'I': // print IRT to stdout (default none)
        irt_stream = &std::cout;
        break;
      case 'i': // print IRT to file:
        irt_stream = new std::ofstream(optarg, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
        break;
      case 'o': // save output in file: (default?)
        out_stream = new std::ofstream(optarg, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
        break;
      default:
        exit(1);
    }
  }
  argc -= optind;
  argv += optind;

  // TODO: read input file names from remainder of argv

  yyparse();

  if(program_declaration == NULL)
    exit(1);

  if(ast_stream)
  {
    ast::PrettyPrinter pp(*ast_stream);
    pp.visit(program_declaration);
  }

  sema::TypeChecker tc;
  tc.visit(program_declaration);

  return 0;
}
