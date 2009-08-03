#ifndef KOMPIS_AST_PRETTY_PRINTER_HPP
#define KOMPIS_AST_PRETTY_PRINTER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class PrettyPrinter : public Visitor
    {
      public:
        PrettyPrinter(std::ostream &out)
          : _out(out), _indentation(0) {}

        void visit(AdditionExpression *);
        void visit(ArrayAssignmentStatement *);
        void visit(ArrayLengthExpression *);
        void visit(ArraySubscriptExpression *);
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
        void visit(IntegerArrayType *);
        void visit(IntegerLiteral *);
        void visit(IntegerType *);
        void visit(LessThanExpression *);
        void visit(MainClassDeclaration *);
        void visit(MethodDeclaration *);
        void visit(MethodDeclarationList *);
        void visit(MultiplicationExpression *);
        void visit(NegationExpression *);
        void visit(NewIntegerArrayExpression *);
        void visit(NewObjectExpression *);
        void visit(ParameterDeclaration *);
        void visit(ParameterDeclarationList *);
        void visit(PrintStatement *);
        void visit(ProgramDeclaration *);
        void visit(StatementList *);
        void visit(SubtractionExpression *);
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
