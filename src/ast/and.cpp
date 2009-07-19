#include "ast/and.hpp"

namespace kompis
{
  namespace ast
  {
    void And::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
