#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ParameterDeclaration::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
