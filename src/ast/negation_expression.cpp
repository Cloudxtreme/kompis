#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void NegationExpression::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
