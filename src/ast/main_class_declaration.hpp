#ifndef KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP
#define KOMPIS_AST_MAIN_CLASS_DECLARATION_HPP

#include <list>
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
        MainClassDeclaration(Identifier *name, Statement *statement) : _name(name), _statement(statement) {}

        void accept(Visitor *);

      //private:
        Identifier *_name;
        Statement *_statement;
    };
  }
}

#endif
