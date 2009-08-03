#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

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

    class VisitorData
    {
      public:
        virtual ~VisitorData() {}
    };

    class Visitor
    {
      public:
        virtual ~Visitor() {}

        virtual VisitorData *visit(AdditionExpression *) = 0;
        virtual VisitorData *visit(AssignmentStatement *) = 0;
        virtual VisitorData *visit(BlockStatement *) = 0;
        virtual VisitorData *visit(BooleanLiteral *) = 0;
        virtual VisitorData *visit(BooleanType *) = 0;
        virtual VisitorData *visit(CallExpression *) = 0;
        virtual VisitorData *visit(ClassDeclaration *) = 0;
        virtual VisitorData *visit(ClassDeclarationList *) = 0;
        virtual VisitorData *visit(ConjunctionExpression *) = 0;
        virtual VisitorData *visit(ExpressionList *) = 0;
        virtual VisitorData *visit(Identifier *) = 0;
        virtual VisitorData *visit(IdentifierExpression *) = 0;
        virtual VisitorData *visit(IdentifierType *) = 0;
        virtual VisitorData *visit(IfThenElseStatement *) = 0;
        virtual VisitorData *visit(IntegerLiteral *) = 0;
        virtual VisitorData *visit(IntegerType *) = 0;
        virtual VisitorData *visit(LessThanExpression *) = 0;
        virtual VisitorData *visit(MainClassDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclaration *) = 0;
        virtual VisitorData *visit(MethodDeclarationList *) = 0;
        virtual VisitorData *visit(MultiplicationExpression *) = 0;
        virtual VisitorData *visit(NegationExpression *) = 0;
        virtual VisitorData *visit(NewObjectExpression *) = 0;
        virtual VisitorData *visit(ParameterDeclaration *) = 0;
        virtual VisitorData *visit(ParameterDeclarationList *) = 0;
        virtual VisitorData *visit(PrintStatement *) = 0;
        virtual VisitorData *visit(ProgramDeclaration *) = 0;
        virtual VisitorData *visit(SubtractionExpression *) = 0;
        virtual VisitorData *visit(StatementList *) = 0;
        virtual VisitorData *visit(ThisExpression *) = 0;
        virtual VisitorData *visit(VariableDeclaration *) = 0;
        virtual VisitorData *visit(VariableDeclarationList *) = 0;
        virtual VisitorData *visit(WhileDoStatement *) = 0;
    };
  }
}

#endif
