#include "ast/boolean_literal.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void BooleanLiteral::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
