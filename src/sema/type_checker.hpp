#ifndef KOMPIS_AST_TYPE_CHECKER_HPP
#define KOMPIS_AST_TYPE_CHECKER_HPP

#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace sema
  {
    using namespace ast;

    class TypeData : public VisitorData
    {
      public:
        virtual ~TypeData() {}
    };

    class TypeChecker : public Visitor
    {
      public:
        TypeChecker() {}

        TypeData *visit(AdditionExpression *);
        TypeData *visit(AssignmentStatement *);
        TypeData *visit(BlockStatement *);
        TypeData *visit(BooleanLiteral *);
        TypeData *visit(BooleanType *);
        TypeData *visit(CallExpression *);
        TypeData *visit(ClassDeclaration *);
        TypeData *visit(ClassDeclarationList *);
        TypeData *visit(ConjunctionExpression *);
        TypeData *visit(ExpressionList *);
        TypeData *visit(Identifier *);
        TypeData *visit(IdentifierExpression *);
        TypeData *visit(IdentifierType *);
        TypeData *visit(IfThenElseStatement *);
        TypeData *visit(IntegerLiteral *);
        TypeData *visit(IntegerType *);
        TypeData *visit(LessThanExpression *);
        TypeData *visit(MainClassDeclaration *);
        TypeData *visit(MethodDeclaration *);
        TypeData *visit(MethodDeclarationList *);
        TypeData *visit(MultiplicationExpression *);
        TypeData *visit(NegationExpression *);
        TypeData *visit(NewObjectExpression *);
        TypeData *visit(ParameterDeclaration *);
        TypeData *visit(ParameterDeclarationList *);
        TypeData *visit(PrintStatement *);
        TypeData *visit(ProgramDeclaration *);
        TypeData *visit(SubtractionExpression *);
        TypeData *visit(StatementList *);
        TypeData *visit(ThisExpression *);
        TypeData *visit(VariableDeclaration *);
        TypeData *visit(VariableDeclarationList *);
        TypeData *visit(WhileDoStatement *);
    };
  }
}

#endif
