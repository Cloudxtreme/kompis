#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void IntegerLiteral::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
