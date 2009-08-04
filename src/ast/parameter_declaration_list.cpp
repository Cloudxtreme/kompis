#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ParameterDeclarationList::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
