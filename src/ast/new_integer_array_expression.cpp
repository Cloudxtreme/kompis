#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void NewIntegerArrayExpression::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
