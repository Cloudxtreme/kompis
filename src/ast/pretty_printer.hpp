#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/integer_literal.hpp"
#include "ast/plus.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {};

        void visit(IntegerLiteral *i)
        {
          _out << i->_value;
        }

        void visit(Plus *p)
        {
          _out << "(+ ";
          p->_left->accept(this);
          _out << " ";
          p->_right->accept(this);
          _out << ")";
        }

      private:
        std::ostream &_out;
    };
  }
}

#endif
