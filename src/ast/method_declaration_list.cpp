#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *MethodDeclarationList::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
