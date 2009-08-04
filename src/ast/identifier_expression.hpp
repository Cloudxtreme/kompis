#ifndef KOMPIS_AST_IDENTIFIER_EXPRESSION_HPP
#define KOMPIS_AST_IDENTIFIER_EXPRESSION_HPP

#include <string>
#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IdentifierExpression : public Expression
    {
      public:
        IdentifierExpression(int line_num, const char *name)
          : Expression(line_num), _name(name) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
