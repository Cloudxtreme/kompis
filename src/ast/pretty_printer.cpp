#include "ast/pretty_printer.hpp"
#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void PrettyPrinter::visit(IntegerLiteral &i)
    {
      _out << i._value;
    }

    void PrettyPrinter::visit(Plus &p)
    {
      _out << "(+ ";
      p._left.accept(*this);
      _out << " ";
      p._right.accept(*this);
      _out << ")";
    }
  }
}
