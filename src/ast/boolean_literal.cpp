#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BooleanLiteral::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
