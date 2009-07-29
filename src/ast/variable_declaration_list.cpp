#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void VariableDeclarationList::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
