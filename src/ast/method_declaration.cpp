#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void MethodDeclaration::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
