#ifndef KOMPIS_AST_TRUE_LITERAL_HPP
#define KOMPIS_AST_TRUE_LITERAL_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class TrueLiteral : public Expression
    {
      public:
        void accept(Visitor &visitor);
    };
  }
}

#endif
