#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ArrayAssignmentStatement::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
