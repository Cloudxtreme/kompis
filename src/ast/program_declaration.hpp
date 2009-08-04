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
        ProgramDeclaration(MainClassDeclaration *main,
                           ClassDeclarationList *classes,
                           int line_num = 0)
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
