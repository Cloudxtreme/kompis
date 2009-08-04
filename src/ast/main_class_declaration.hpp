#ifndef KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP
#define KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Statement;
    class Visitor;
    class VisitorData;

    class MainClassDeclaration : public Node
    {
      public:
        MainClassDeclaration(Statement *statement,
                             int line_num = 0)
          : Node(line_num),
            _statement(statement) {}

        VisitorData *accept(Visitor *);

        Statement *_statement;
    };
  }
}

#endif
