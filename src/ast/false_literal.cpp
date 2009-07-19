#include "ast/false_literal.hpp"

namespace kompis
{
  namespace ast
  {
    void FalseLiteral::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
