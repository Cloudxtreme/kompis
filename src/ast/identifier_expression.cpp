#include "ast/ast.hpp"

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
