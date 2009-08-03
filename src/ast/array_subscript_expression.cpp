#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ArraySubscriptExpression::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
