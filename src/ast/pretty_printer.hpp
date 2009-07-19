#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class IntegerLiteral;
    class Minus;
    class Plus;
    class Times;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(IntegerLiteral &);
        void visit(Minus &);
        void visit(Plus &);
        void visit(Times &);

      private:
        std::ostream &_out;
    };
  }
}

#endif
