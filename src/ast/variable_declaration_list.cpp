#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *VariableDeclarationList::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
