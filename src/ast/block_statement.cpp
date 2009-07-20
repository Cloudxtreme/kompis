#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void BlockStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
