#include "ast/plus.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void Plus::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
