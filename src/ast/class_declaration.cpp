#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void ClassDeclaration::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
