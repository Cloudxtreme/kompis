#include "ast/method_declaration.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void MethodDeclaration::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
