#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *PrintStatement::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
