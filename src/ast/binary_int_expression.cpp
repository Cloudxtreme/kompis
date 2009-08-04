#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    namespace binop
    {
      const char *str(BinaryOperation b)
      {
        switch(b)
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
      }
    }

    VisitorData *BinaryIntExpression::accept(Visitor *visitor)
    {
      return visitor->visit(this);
    }
  }
}
