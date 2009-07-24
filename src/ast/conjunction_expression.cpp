#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ConjunctionExpression::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
