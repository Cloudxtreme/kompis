#include "ast/times.hpp"

namespace kompis
{
  namespace ast
  {
    void Times::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
