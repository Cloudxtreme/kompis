#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BlockStatement::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
