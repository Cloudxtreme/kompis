#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ParameterDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
