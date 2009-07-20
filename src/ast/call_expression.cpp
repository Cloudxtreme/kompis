#include "ast/ast.hpp"

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
