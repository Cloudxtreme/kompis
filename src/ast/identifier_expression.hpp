#ifndef KOMPIS_AST_IDENTIFIER_EXPRESSION_HPP
#define KOMPIS_AST_IDENTIFIER_EXPRESSION_HPP

#include <string>
#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class IdentifierExpression : public Expression
    {
      public:
        IdentifierExpression(char *name) : _name(name) {}

        void accept(Visitor &visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
