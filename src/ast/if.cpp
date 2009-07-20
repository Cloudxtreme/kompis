#include "ast/if.hpp"

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
