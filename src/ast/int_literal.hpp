#ifndef KOMPIS_AST_INT_LITERAL_HPP
#define KOMPIS_AST_INT_LITERAL_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntLiteral : public Expression
    {
      public:
        IntLiteral(int value,
                       int line_num = 0)
          : Expression(line_num),
            _value(value) {}

        VisitorData *accept(Visitor *visitor);

        int _value;
    };
  }
}

#endif
