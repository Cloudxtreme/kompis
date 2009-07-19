#include "ast/plus.hpp"

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
