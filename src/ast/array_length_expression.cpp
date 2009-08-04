#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ArrayLengthExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
