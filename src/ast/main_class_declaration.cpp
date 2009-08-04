#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *MainClassDeclaration::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
