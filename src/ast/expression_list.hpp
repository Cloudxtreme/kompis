#ifndef KOMPIS_AST_EXPRESSION_LIST_HPP
#define KOMPIS_AST_EXPRESSION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class ExpressionList : public List<Expression>
    {
      public:
        VisitorData *accept(Visitor *);
    };
  }
}

#endif
