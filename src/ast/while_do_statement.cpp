#include "ast/while_do_statement.hpp"

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
