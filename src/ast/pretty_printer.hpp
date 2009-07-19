#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class And;
    class FalseLiteral;
    class Identifier;
    class IntegerLiteral;
    class LessThan;
    class Minus;
    class Not;
    class Plus;
    class Times;
    class TrueLiteral;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(And &);
        void visit(FalseLiteral &);
        void visit(Identifier &);
        void visit(IntegerLiteral &);
        void visit(LessThan &);
        void visit(Minus &);
        void visit(Not &);
        void visit(Plus &);
        void visit(Times &);
        void visit(TrueLiteral &);

      private:
        std::ostream &_out;
    };
  }
}

#endif
