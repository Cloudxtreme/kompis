#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ClassDeclaration::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
