#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *NewIntArrayExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
