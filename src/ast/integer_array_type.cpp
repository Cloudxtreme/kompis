#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntegerArrayType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
