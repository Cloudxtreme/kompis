#include "ast/parameter_declaration.hpp"
#include "ast/visitor.hpp"

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
