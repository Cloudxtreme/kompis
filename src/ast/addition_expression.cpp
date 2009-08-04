#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *AdditionExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
