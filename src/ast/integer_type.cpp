#include "ast/integer_type.hpp"
#include "ast/visitor.hpp"

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
