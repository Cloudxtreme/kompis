#include "ast/identifier_expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void IdentifierExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
