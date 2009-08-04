#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *MultiplicationExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
