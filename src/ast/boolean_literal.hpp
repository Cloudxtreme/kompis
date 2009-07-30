#ifndef KOMPIS_AST_BOOLEAN_LITERAL_HPP
#define KOMPIS_AST_BOOLEAN_LITERAL_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class BooleanLiteral : public Expression
    {
      public:
        BooleanLiteral(bool value)
          : _value(value) {}

        void accept(Visitor *visitor);

      //private:
        bool _value;
    };
  }
}

#endif
