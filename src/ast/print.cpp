#include "ast/print.hpp"

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
