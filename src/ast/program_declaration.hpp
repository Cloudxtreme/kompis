#ifndef KOMPIS_AST_PROGRAM_DECLARATION_HPP
#define KOMPIS_AST_PROGRAM_DECLARATION_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class ClassDeclaration;
    class MainClassDeclaration;
    class Visitor;

    class ProgramDeclaration : public Node
    {
      public:
        ProgramDeclaration(MainClassDeclaration *main, std::list<ClassDeclaration *> classes) : _main(main), _classes(classes) {}

        void accept(Visitor *);

      //private:
        MainClassDeclaration *_main;
        std::list<ClassDeclaration *> _classes;
    };
  }
}

#endif
