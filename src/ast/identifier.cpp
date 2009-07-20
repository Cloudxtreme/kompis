#include "ast/identifier.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void Identifier::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
