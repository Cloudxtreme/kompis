#include "ast/minus.hpp"
#include "ast/visitor.hpp"

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
