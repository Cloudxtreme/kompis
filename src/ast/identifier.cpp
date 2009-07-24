#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void Identifier::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
