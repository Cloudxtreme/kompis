#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void MethodDeclarationList::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
