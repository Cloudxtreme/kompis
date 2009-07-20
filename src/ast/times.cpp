#include "ast/times.hpp"
#include "ast/visitor.hpp"

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
