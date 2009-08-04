#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *NewObjectExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
