#include "ast/print.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void Print::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
