#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void IfThenElseStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
