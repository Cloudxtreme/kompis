#include "ast/ast.hpp"

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
