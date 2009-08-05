#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *UnaryBooleanExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }

    const char *UnaryBooleanExpression::op_str()
    {
      switch(_op)
      {
        case BOOLEAN_NEG:
          return "!";
      }

      return NULL; // Will not happen.
    }
  }
}
