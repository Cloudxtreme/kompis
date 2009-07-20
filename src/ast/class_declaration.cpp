#include "ast/class_declaration.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void ClassDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
