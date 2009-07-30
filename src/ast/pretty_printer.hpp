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
    class ClassDeclarationList;
    class ConjunctionExpression;
    class ExpressionList;
    class Identifier;
    class IdentifierExpression;
    class IdentifierType;
    class IfThenElseStatement;
    class IntegerLiteral;
    class IntegerType;
    class LessThanExpression;
    class MainClassDeclaration;
    class MethodDeclaration;
    class MethodDeclarationList;
    class MultiplicationExpression;
    class NegationExpression;
    class NewObjectExpression;
    class ParameterDeclaration;
    class ParameterDeclarationList;
    class PrintStatement;
    class ProgramDeclaration;
    class StatementList;
    class SubtractionExpression;
    class ThisExpression;
    class VariableDeclaration;
    class VariableDeclarationList;
    class WhileDoStatement;

    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out)
          : _out(out), _indentation(0) {}

        void visit(AdditionExpression *);
        void visit(AssignmentStatement *);
        void visit(BlockStatement *);
        void visit(BooleanLiteral *);
        void visit(BooleanType *);
        void visit(CallExpression *);
        void visit(ClassDeclaration *);
        void visit(ClassDeclarationList *);
        void visit(ConjunctionExpression *);
        void visit(ExpressionList *);
        void visit(Identifier *);
        void visit(IdentifierExpression *);
        void visit(IdentifierType *);
        void visit(IfThenElseStatement *);
        void visit(IntegerLiteral *);
        void visit(IntegerType *);
        void visit(LessThanExpression *);
        void visit(MainClassDeclaration *);
        void visit(MethodDeclaration *);
        void visit(MethodDeclarationList *);
        void visit(MultiplicationExpression *);
        void visit(NegationExpression *);
        void visit(NewObjectExpression *);
        void visit(ParameterDeclaration *);
        void visit(ParameterDeclarationList *);
        void visit(PrintStatement *);
        void visit(ProgramDeclaration *);
        void visit(SubtractionExpression *);
        void visit(StatementList *);
        void visit(ThisExpression *);
        void visit(VariableDeclaration *);
        void visit(VariableDeclarationList *);
        void visit(WhileDoStatement *);

      private:
        void indent();

        std::ostream &_out;
        int _indentation;
    };
  }
}

#endif
