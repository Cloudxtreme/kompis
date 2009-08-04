#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IdentifierExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
