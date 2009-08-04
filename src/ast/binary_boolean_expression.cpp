#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BinaryBooleanExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }

    const char *BinaryBooleanExpression::op_str()
    {
      switch(_op)
      {
        case BOOLEAN_AND:
          return "&&";
        case BOOLEAN_OR:
          return "||";
      }
    }
  }
}
