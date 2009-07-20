#include "ast/identifier_type.hpp"
#include "ast/visitor.hpp"

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
