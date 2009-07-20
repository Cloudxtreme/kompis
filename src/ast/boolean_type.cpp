#include "ast/boolean_type.hpp"

namespace kompis
{
  namespace ast
  {
    void BooleanType::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
