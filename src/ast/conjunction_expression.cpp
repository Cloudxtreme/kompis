#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ConjunctionExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
