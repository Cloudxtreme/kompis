#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BooleanType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
