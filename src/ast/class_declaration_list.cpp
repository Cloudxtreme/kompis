#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ClassDeclarationList::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}