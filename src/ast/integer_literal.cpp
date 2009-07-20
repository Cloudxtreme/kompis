#include "ast/integer_literal.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void IntegerLiteral::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
