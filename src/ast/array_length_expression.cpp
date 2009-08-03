#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ArrayLengthExpression::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
