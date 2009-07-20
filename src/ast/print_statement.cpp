#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void PrintStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
