#ifndef KOMPIS_AST_PROGRAM_DECLARATION_HPP
#define KOMPIS_AST_PROGRAM_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class ClassDeclaration;
    class MainClassDeclaration;
    class Visitor;
    class VisitorData;

    class ProgramDeclaration : public Node
    {
      public:
        ProgramDeclaration(int line_num,
                           MainClassDeclaration *main,
                           ClassDeclarationList *classes)
          : Node(line_num),
            _main(main),
            _classes(classes) {}

        VisitorData *accept(Visitor *);

      //private:
        MainClassDeclaration *_main;
        ClassDeclarationList *_classes;
    };
  }
}

#endif
