#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class AdditionExpression;
    class AssignmentStatement;
    class BlockStatement;
    class BooleanLiteral;
    class BooleanType;
    class CallExpression;
    class ClassDeclaration;
    class ConjunctionExpression;
    class Identifier;
    class IdentifierExpression;
    class IdentifierType;
    class IfThenElseStatement;
    class IntegerLiteral;
    class IntegerType;
    class LessThanExpression;
    class MainClassDeclaration;
    class MethodDeclaration;
    class MultiplicationExpression;
    class NegationExpression;
    class NewObjectExpression;
    class ParameterDeclaration;
    class PrintStatement;
    class ProgramDeclaration;
    class SubtractionExpression;
    class ThisExpression;
    class VariableDeclaration;
    class WhileDoStatement;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out) : _out(out) {}

        void visit(AdditionExpression *);
        void visit(AssignmentStatement *);
        void visit(BlockStatement *);
        void visit(BooleanLiteral *);
        void visit(BooleanType *);
        void visit(CallExpression *);
        void visit(ClassDeclaration *);
        void visit(ConjunctionExpression *);
        void visit(Identifier *);
        void visit(IdentifierExpression *);
        void visit(IdentifierType *);
        void visit(IfThenElseStatement *);
        void visit(IntegerLiteral *);
        void visit(IntegerType *);
        void visit(LessThanExpression *);
        void visit(MainClassDeclaration *);
        void visit(MethodDeclaration *);
        void visit(MultiplicationExpression *);
        void visit(NegationExpression *);
        void visit(NewObjectExpression *);
        void visit(ParameterDeclaration *);
        void visit(PrintStatement *);
        void visit(ProgramDeclaration *);
        void visit(SubtractionExpression *);
        void visit(ThisExpression *);
        void visit(VariableDeclaration *);
        void visit(WhileDoStatement *);

      private:
        std::ostream &_out;
    };
  }
}

#endif
