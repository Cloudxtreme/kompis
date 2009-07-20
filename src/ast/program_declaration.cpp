#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ProgramDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
