#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

namespace kompis
{
  namespace ast
  {
    class ArrayAssignmentStatement;
    class ArrayLengthExpression;
    class ArraySubscriptExpression;
    class AssignmentStatement;
    class BinaryBooleanExpression;
    class BinaryIntBooleanExpression;
    class BinaryIntExpression;
    class BlockStatement;
    class BooleanLiteral;
    class BooleanType;
    class CallExpression;
    class ClassDeclaration;
    class ClassDeclarationList;
    class ExpressionList;
    class Identifier;
    class IdentifierExpression;
    class IdentifierType;
    class IfThenElseStatement;
    class IntegerArrayType;
    class IntegerLiteral;
    class IntegerType;
    class MainClassDeclaration;
    class MethodDeclaration;
    class MethodDeclarationList;
    class NewIntegerArrayExpression;
    class NewObjectExpression;
    class ParameterDeclaration;
    class ParameterDeclarationList;
    class PrintStatement;
    class ProgramDeclaration;
    class StatementList;
    class ThisExpression;
    class UnaryBooleanExpression;
    class VariableDeclaration;
    class VariableDeclarationList;
    class WhileDoStatement;

    class VisitorData
    {
      public:
        virtual ~VisitorData() {}
    };

    class Visitor
    {
      public:
        virtual ~Visitor() {}

        virtual VisitorData *visit(ArrayAssignmentStatement *) = 0;
        virtual VisitorData *visit(ArrayLengthExpression *) = 0;
        virtual VisitorData *visit(ArraySubscriptExpression *) = 0;
        virtual VisitorData *visit(AssignmentStatement *) = 0;
        virtual VisitorData *visit(BinaryBooleanExpression *) = 0;
        virtual VisitorData *visit(BinaryIntBooleanExpression *) = 0;
        virtual VisitorData *visit(BinaryIntExpression *) = 0;
        virtual VisitorData *visit(BlockStatement *) = 0;
        virtual VisitorData *visit(BooleanLiteral *) = 0;
        virtual VisitorData *visit(BooleanType *) = 0;
        virtual VisitorData *visit(CallExpression *) = 0;
        virtual VisitorData *visit(ClassDeclaration *) = 0;
        virtual VisitorData *visit(ClassDeclarationList *) = 0;
        virtual VisitorData *visit(ExpressionList *) = 0;
        virtual VisitorData *visit(Identifier *) = 0;
        virtual VisitorData *visit(IdentifierExpression *) = 0;
        virtual VisitorData *visit(IdentifierType *) = 0;
        virtual VisitorData *visit(IfThenElseStatement *) = 0;
        virtual VisitorData *visit(IntegerArrayType *) = 0;
        virtual VisitorData *visit(IntegerLiteral *) = 0;
        virtual VisitorData *visit(IntegerType *) = 0;
        virtual VisitorData *visit(MainClassDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclarationList *) = 0;
        virtual VisitorData *visit(NewIntegerArrayExpression *) = 0;
        virtual VisitorData *visit(NewObjectExpression *) = 0;
        virtual VisitorData *visit(ParameterDeclaration *) = 0;
        virtual VisitorData *visit(ParameterDeclarationList *) = 0;
        virtual VisitorData *visit(PrintStatement *) = 0;
        virtual VisitorData *visit(ProgramDeclaration *) = 0;
        virtual VisitorData *visit(StatementList *) = 0;
        virtual VisitorData *visit(ThisExpression *) = 0;
        virtual VisitorData *visit(UnaryBooleanExpression *) = 0;
        virtual VisitorData *visit(VariableDeclaration *) = 0;
        virtual VisitorData *visit(VariableDeclarationList *) = 0;
        virtual VisitorData *visit(WhileDoStatement *) = 0;
    };
  }
}

#endif
