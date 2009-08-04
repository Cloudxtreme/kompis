#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BinaryIntBooleanExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }

    const char *BinaryIntBooleanExpression::op_str()
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
    }
  }
}
