#include "ast/not.hpp"

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
