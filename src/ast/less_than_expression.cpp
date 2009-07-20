#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void LessThanExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
