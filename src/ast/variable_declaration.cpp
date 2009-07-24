#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void VariableDeclaration::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
