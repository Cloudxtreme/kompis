#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ProgramDeclaration::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
