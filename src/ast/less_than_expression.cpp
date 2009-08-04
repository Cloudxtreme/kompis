#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *LessThanExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
