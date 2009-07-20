#include "ast/if_then_else_statement.hpp"
#include "ast/visitor.hpp"

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