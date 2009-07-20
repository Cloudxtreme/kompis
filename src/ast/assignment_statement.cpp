#include "ast/assignment_statement.hpp"
#include "ast/visitor.hpp"

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
