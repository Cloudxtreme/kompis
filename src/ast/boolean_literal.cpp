#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void BooleanLiteral::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
