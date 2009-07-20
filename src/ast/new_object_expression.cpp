#include "ast/ast.hpp"

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
