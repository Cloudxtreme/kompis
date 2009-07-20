#include "ast/while_do_statement.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void WhileDoStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
