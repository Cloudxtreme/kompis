#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void StatementList::accept(Visitor *visitor)
    {
      visitor->visit(this);
    }
  }
}
