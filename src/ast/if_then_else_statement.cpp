#include "ast/if_then_else_statement.hpp"

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
