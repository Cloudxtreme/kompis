#include "ast/identifier.hpp"

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
