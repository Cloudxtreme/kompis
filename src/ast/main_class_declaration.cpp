#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void MainClassDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
