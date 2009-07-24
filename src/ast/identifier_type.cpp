#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void IdentifierType::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
