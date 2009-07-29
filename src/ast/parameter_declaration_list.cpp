#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ParameterDeclarationList::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
