#include "ast/call_expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void CallExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
