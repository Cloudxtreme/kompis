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
          : _out(out),
            _indentation(0) {}

        VisitorData *visit(AssignmentStatement *);
        VisitorData *visit(BinaryBooleanExpression *);
        VisitorData *visit(BinaryIntExpression *);
        VisitorData *visit(BlockStatement *);
        VisitorData *visit(BooleanLiteral *);
        VisitorData *visit(BooleanType *);
        VisitorData *visit(CallExpression *);
        VisitorData *visit(ClassDeclaration *);
        VisitorData *visit(ClassDeclarationList *);
        VisitorData *visit(ComparisonExpression *);
        VisitorData *visit(ExpressionList *);
        VisitorData *visit(Identifier *);
        VisitorData *visit(IdentifierExpression *);
        VisitorData *visit(IdentifierType *);
        VisitorData *visit(IfElseStatement *);
        VisitorData *visit(IntArrayAssignmentStatement *);
        VisitorData *visit(IntArrayLengthExpression *);
        VisitorData *visit(IntArraySubscriptExpression *);
        VisitorData *visit(IntArrayType *);
        VisitorData *visit(IntLiteral *);
        VisitorData *visit(IntType *);
        VisitorData *visit(MainClassDeclaration *);
        VisitorData *visit(MethodDeclaration *);
        VisitorData *visit(MethodDeclarationList *);
        VisitorData *visit(NewIntArrayExpression *);
        VisitorData *visit(NewObjectExpression *);
        VisitorData *visit(ParameterDeclaration *);
        VisitorData *visit(ParameterDeclarationList *);
        VisitorData *visit(PrintStatement *);
        VisitorData *visit(ProgramDeclaration *);
        VisitorData *visit(StatementList *);
        VisitorData *visit(ThisExpression *);
        VisitorData *visit(UnaryBooleanExpression *);
        VisitorData *visit(VariableDeclaration *);
        VisitorData *visit(VariableDeclarationList *);
        VisitorData *visit(WhileStatement *);

      private:
        void indent();

        std::ostream &_out;
        int _indentation;
    };
  }
}

#endif
