#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    VisitorData *BinaryIntExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }

    const char *BinaryIntExpression::op_str()
    {
      switch(_op)
      {
        case ADD:
          return "+";
        case SUB:
          return "-";
        case MUL:
          return "*";
        case DIV:
          return "/";
      }

      return NULL; // Will not happen.
    }
  }
}
