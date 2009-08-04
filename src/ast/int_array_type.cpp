#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntArrayType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
