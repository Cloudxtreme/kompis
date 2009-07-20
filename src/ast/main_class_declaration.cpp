#include "ast/main_class_declaration.hpp"
#include "ast/visitor.hpp"

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
