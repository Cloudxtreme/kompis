#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void AdditionExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
