#include "ast/minus.hpp"

namespace kompis
{
  namespace ast
  {
    void Minus::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
