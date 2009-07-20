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
    class BooleanType;
    class CallExpression;
    class Identifier;
    class IdentifierExpression;
    class IdentifierType;
    class IfThenElseStatement;
    class IntegerLiteral;
    class IntegerType;
    class LessThan;
    class Minus;
    class NewObjectExpression;
    class Not;
    class ParameterDeclaration;
    class Plus;
    class Print;
    class ThisExpression;
    class Times;
    class VariableDeclaration;
    class WhileDoStatement;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(And &);
        void visit(AssignmentStatement &);
        void visit(BooleanLiteral &);
        void visit(BooleanType &);
        void visit(CallExpression &);
        void visit(Identifier &);
        void visit(IdentifierExpression &);
        void visit(IdentifierType &);
        void visit(IfThenElseStatement &);
        void visit(IntegerLiteral &);
        void visit(IntegerType &);
        void visit(LessThan &);
        void visit(Minus &);
        void visit(NewObjectExpression &);
        void visit(Not &);
        void visit(ParameterDeclaration &);
        void visit(Plus &);
        void visit(Print &);
        void visit(ThisExpression &);
        void visit(Times &);
        void visit(VariableDeclaration &);
        void visit(WhileDoStatement &);

      private:
        std::ostream &_out;
    };
  }
}

#endif
