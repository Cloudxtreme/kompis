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

    class Visitor
    {
      public:
        virtual ~Visitor() {}

        virtual void visit(AdditionExpression *) = 0;
        virtual void visit(AssignmentStatement *) = 0;
        virtual void visit(BlockStatement *) = 0;
        virtual void visit(BooleanLiteral *) = 0;
        virtual void visit(BooleanType *) = 0;
        virtual void visit(CallExpression *) = 0;
        virtual void visit(ClassDeclaration *) = 0;
        virtual void visit(ClassDeclarationList *) = 0;
        virtual void visit(ConjunctionExpression *) = 0;
        virtual void visit(ExpressionList *) = 0;
        virtual void visit(Identifier *) = 0;
        virtual void visit(IdentifierExpression *) = 0;
        virtual void visit(IdentifierType *) = 0;
        virtual void visit(IfThenElseStatement *) = 0;
        virtual void visit(IntegerLiteral *) = 0;
        virtual void visit(IntegerType *) = 0;
        virtual void visit(LessThanExpression *) = 0;
        virtual void visit(MainClassDeclaration *) = 0;
        virtual void visit(MethodDeclaration *) = 0;
        virtual void visit(MethodDeclarationList *) = 0;
        virtual void visit(MultiplicationExpression *) = 0;
        virtual void visit(NegationExpression *) = 0;
        virtual void visit(NewObjectExpression *) = 0;
        virtual void visit(ParameterDeclaration *) = 0;
        virtual void visit(ParameterDeclarationList *) = 0;
        virtual void visit(PrintStatement *) = 0;
        virtual void visit(ProgramDeclaration *) = 0;
        virtual void visit(SubtractionExpression *) = 0;
        virtual void visit(StatementList *) = 0;
        virtual void visit(ThisExpression *) = 0;
        virtual void visit(VariableDeclaration *) = 0;
        virtual void visit(VariableDeclarationList *) = 0;
        virtual void visit(WhileDoStatement *) = 0;
    };
  }
}

#endif
