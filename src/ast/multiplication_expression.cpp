#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void MultiplicationExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}