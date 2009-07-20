#include "ast/variable_declaration.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void VariableDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
