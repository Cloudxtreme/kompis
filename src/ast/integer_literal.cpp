#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntegerLiteral::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
