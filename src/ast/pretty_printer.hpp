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

        VisitorData *visit(ArrayAssignmentStatement *);
        VisitorData *visit(ArrayLengthExpression *);
        VisitorData *visit(ArraySubscriptExpression *);
        VisitorData *visit(AssignmentStatement *);
        VisitorData *visit(BinaryBooleanExpression *);
        VisitorData *visit(BinaryIntBooleanExpression *);
        VisitorData *visit(BinaryIntExpression *);
        VisitorData *visit(BlockStatement *);
        VisitorData *visit(BooleanLiteral *);
        VisitorData *visit(BooleanType *);
        VisitorData *visit(CallExpression *);
        VisitorData *visit(ClassDeclaration *);
        VisitorData *visit(ClassDeclarationList *);
        VisitorData *visit(ExpressionList *);
        VisitorData *visit(Identifier *);
        VisitorData *visit(IdentifierExpression *);
        VisitorData *visit(IdentifierType *);
        VisitorData *visit(IfThenElseStatement *);
        VisitorData *visit(IntegerArrayType *);
        VisitorData *visit(IntegerLiteral *);
        VisitorData *visit(IntegerType *);
        VisitorData *visit(MainClassDeclaration *);
        VisitorData *visit(MethodDeclaration *);
        VisitorData *visit(MethodDeclarationList *);
        VisitorData *visit(NewIntegerArrayExpression *);
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
        VisitorData *visit(WhileDoStatement *);

      private:
        void indent();

        std::ostream &_out;
        int _indentation;
    };
  }
}

#endif
