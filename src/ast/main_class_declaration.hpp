#ifndef KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP
#define KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class Statement;
    class Visitor;
    class VisitorData;

    class MainClassDeclaration : public Node
    {
      public:
        MainClassDeclaration(int line_num, Statement *statement)
          : Node(line_num), _statement(statement) {}

        VisitorData *accept(Visitor *);

      //private:
        Statement *_statement;
    };
  }
}

#endif
