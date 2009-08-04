#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
