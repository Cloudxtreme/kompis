#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *AssignmentStatement::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
