#include "ast/boolean_type.hpp"
#include "ast/visitor.hpp"

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
