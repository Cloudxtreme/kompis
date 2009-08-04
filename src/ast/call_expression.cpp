#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *CallExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
