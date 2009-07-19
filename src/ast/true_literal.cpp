#include "ast/true_literal.hpp"

namespace kompis
{
  namespace ast
  {
    void TrueLiteral::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
