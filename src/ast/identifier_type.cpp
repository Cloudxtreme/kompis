#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IdentifierType::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
