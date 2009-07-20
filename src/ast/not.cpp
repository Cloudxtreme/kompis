#include "ast/not.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void Not::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
