#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

namespace kompis
{
  namespace ast
  {
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
    class IfElseStatement;
    class IntArrayAssignmentStatement;
    class IntArrayLengthExpression;
    class IntArraySubscriptExpression;
    class IntArrayType;
    class IntLiteral;
    class IntType;
    class MainClassDeclaration;
    class MethodDeclaration;
    class MethodDeclarationList;
    class NewIntArrayExpression;
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
    class WhileStatement;

    class VisitorData
    {
      public:
        virtual ~VisitorData() {}
    };

    class Visitor
    {
      public:
        virtual ~Visitor() {}

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
        virtual VisitorData *visit(IfElseStatement *) = 0;
        virtual VisitorData *visit(IntArrayAssignmentStatement *) = 0;
        virtual VisitorData *visit(IntArrayLengthExpression *) = 0;
        virtual VisitorData *visit(IntArraySubscriptExpression *) = 0;
        virtual VisitorData *visit(IntArrayType *) = 0;
        virtual VisitorData *visit(IntLiteral *) = 0;
        virtual VisitorData *visit(IntType *) = 0;
        virtual VisitorData *visit(MainClassDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclarationList *) = 0;
        virtual VisitorData *visit(NewIntArrayExpression *) = 0;
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
        virtual VisitorData *visit(WhileStatement *) = 0;
    };
  }
}

#endif
