#include "ast/this_expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void ThisExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
