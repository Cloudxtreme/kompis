#include "ast/less_than.hpp"

namespace kompis
{
  namespace ast
  {
    void LessThan::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
