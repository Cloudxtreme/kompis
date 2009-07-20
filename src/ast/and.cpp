#include "ast/and.hpp"
#include "ast/visitor.hpp"

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
