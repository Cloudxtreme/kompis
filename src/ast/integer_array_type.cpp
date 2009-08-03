#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void IntegerArrayType::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
