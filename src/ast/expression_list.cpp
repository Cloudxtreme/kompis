#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ExpressionList::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
