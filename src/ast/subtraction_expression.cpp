#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *SubtractionExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
