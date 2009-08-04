#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntegerType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
