#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IfThenElseStatement::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
