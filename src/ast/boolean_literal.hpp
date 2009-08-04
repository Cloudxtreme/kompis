#ifndef KOMPIS_AST_BOOLEAN_LITERAL_HPP
#define KOMPIS_AST_BOOLEAN_LITERAL_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class BooleanLiteral : public Expression
    {
      public:
        BooleanLiteral(int line_num, bool value)
          : Expression(line_num), _value(value) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        bool _value;
    };
  }
}

#endif
