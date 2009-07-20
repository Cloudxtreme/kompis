#include "ast/identifier_type.hpp"

namespace kompis
{
  namespace ast
  {
    void IdentifierType::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
