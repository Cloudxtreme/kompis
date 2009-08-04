#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *IntArrayAssignmentStatement::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
