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

    class MainClassDeclaration : public Node
    {
      public:
        MainClassDeclaration(Statement *statement) : _statement(statement) {}

        void accept(Visitor *);

      //private:
        Statement *_statement;
    };
  }
}

#endif
