#include "ast/assign.hpp"

namespace kompis
{
  namespace ast
  {
    void AssignmentStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
