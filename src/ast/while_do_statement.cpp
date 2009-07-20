#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void WhileDoStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
