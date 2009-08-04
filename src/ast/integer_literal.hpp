#ifndef KOMPIS_AST_INTEGER_LITERAL_HPP
#define KOMPIS_AST_INTEGER_LITERAL_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntegerLiteral : public Expression
    {
      public:
        IntegerLiteral(int line_num, int value)
          : Expression(line_num), _value(value) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        int _value;
    };
  }
}

#endif
