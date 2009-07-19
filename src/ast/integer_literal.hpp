#ifndef KOMPIS_AST_INTEGER_LITERAL_HPP
#define KOMPIS_AST_INTEGER_LITERAL_HPP

#include "ast/expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class IntegerLiteral : public Expression
    {
      public:
        IntegerLiteral(int value) : _value(value) {}

        void accept(Visitor *visitor)
        {
          visitor->visit(this);
        }

      //private:
        int _value;
    };
  }
}

#endif
