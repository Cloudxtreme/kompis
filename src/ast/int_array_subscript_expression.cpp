#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntArraySubscriptExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
