#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ArraySubscriptExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
