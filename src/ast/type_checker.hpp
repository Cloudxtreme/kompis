#ifndef KOMPIS_AST_TYPE_CHECKER_HPP
#define KOMPIS_AST_TYPE_CHECKER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class TypeChecker : public Visitor
    {
      public:
        TypeChecker() {}

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
    };
  }
}

#endif
