#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *StatementList::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
