#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *NewIntegerArrayExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
