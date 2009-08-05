#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *ComparisonExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }

    const char *ComparisonExpression::op_str()
    {
      switch(_op)
      {
        case EQ:
          return "==";
        case NE:
          return "!=";
        case LT:
          return "<";
        case LE:
          return "<=";
        case GT:
          return ">";
        case GE:
          return ">=";
      }

      return NULL; // Will not happen.
    }
  }
}
