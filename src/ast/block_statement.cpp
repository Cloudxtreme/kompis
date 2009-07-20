#include "ast/block_statement.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    void BlockStatement::accept(Visitor &visitor)
    {
      visitor.visit(*this);
    }
  }
}
