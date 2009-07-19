#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class IntegerLiteral;
    class Plus;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(IntegerLiteral *i);
        void visit(Plus *p);

      private:
        std::ostream &_out;
    };
  }
}

#endif
