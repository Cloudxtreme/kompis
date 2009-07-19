#include "ast/pretty_printer.hpp"
#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void PrettyPrinter::visit(And &a)
    {
      _out << "(and ";
      a._left.accept(*this);
      _out << " ";
      a._right.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(FalseLiteral &f)
    {
      _out << "false";
    }

    void PrettyPrinter::visit(IntegerLiteral &i)
    {
      _out << i._value;
    }

    void PrettyPrinter::visit(LessThan &l)
    {
      _out << "(< ";
      l._left.accept(*this);
      _out << " ";
      l._right.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(Minus &m)
    {
      _out << "(- ";
      m._left.accept(*this);
      _out << " ";
      m._right.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(Not &n)
    {
      _out << "(not ";
      n._expr.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(Plus &p)
    {
      _out << "(+ ";
      p._left.accept(*this);
      _out << " ";
      p._right.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(Times &t)
    {
      _out << "(* ";
      t._left.accept(*this);
      _out << " ";
      t._right.accept(*this);
      _out << ")";
    }

    void PrettyPrinter::visit(TrueLiteral &t)
    {
      _out << "true";
    }
  }
}
