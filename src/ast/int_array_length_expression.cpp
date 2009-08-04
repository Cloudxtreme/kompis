#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntArrayLengthExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
