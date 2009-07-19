#include "ast/integer_literal.hpp"

namespace kompis
{
  namespace ast
  {
    void IntegerLiteral::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
