#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void IntegerType::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
