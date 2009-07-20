#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class And;
    class AssignmentStatement;
    class BooleanLiteral;
    class Identifier;
    class IfThenElseStatement;
    class IntegerLiteral;
    class LessThan;
    class Minus;
    class Not;
    class Plus;
    class Print;
    class Times;
    class TrueLiteral;
    class WhileDoStatement;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(And &);
        void visit(AssignmentStatement &);
        void visit(BooleanLiteral &);
        void visit(Identifier &);
        void visit(IfThenElseStatement &);
        void visit(IntegerLiteral &);
        void visit(LessThan &);
        void visit(Minus &);
        void visit(Not &);
        void visit(Plus &);
        void visit(Print &);
        void visit(Times &);
        void visit(WhileDoStatement &);

      private:
        std::ostream &_out;
    };
  }
}

#endif
