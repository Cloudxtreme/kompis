#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void SubtractionExpression::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
