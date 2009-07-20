#include "ast/new_object_expression.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void NewObjectExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
