#include "ast/assignment_statement.hpp"

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
