#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *MethodDeclaration::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
