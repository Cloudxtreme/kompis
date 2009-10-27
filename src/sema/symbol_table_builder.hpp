#ifndef KOMPIS_SEMA_SYMBOL_TABLE_BUILDER_HPP
#define KOMPIS_SEMA_SYMBOL_TABLE_BUILDER_HPP

#include <map>
#include <ostream>
#include "ast/visitor.hpp"

namespace kompis
{
  namespace sema
  {
    using namespace ast;

    class SymbolData : public VisitorData
    {
      public:
        SymbolData() {}

        // union (or something) of:
        // - classes []
        // - class {}
        // - methods []
        // - method {}
        // - variables []
        // - variable {}
        // - type: boolean, int, int array, class {}
    };

    class SymbolTableBuilder : public Visitor
    {
      public:
        SymbolTableBuilder() {}

        SymbolData *visit(AssignmentStatement *);
        SymbolData *visit(BinaryBooleanExpression *);
        SymbolData *visit(BinaryIntExpression *);
        SymbolData *visit(BlockStatement *);
        SymbolData *visit(BooleanLiteral *);
        SymbolData *visit(BooleanType *);
        SymbolData *visit(CallExpression *);
        SymbolData *visit(ClassDeclaration *);
        SymbolData *visit(ClassDeclarationList *);
        SymbolData *visit(ComparisonExpression *);
        SymbolData *visit(ExpressionList *);
        SymbolData *visit(Identifier *);
        SymbolData *visit(IdentifierExpression *);
        SymbolData *visit(IdentifierType *);
        SymbolData *visit(IfElseStatement *);
        SymbolData *visit(IntArrayAssignmentStatement *);
        SymbolData *visit(IntArrayLengthExpression *);
        SymbolData *visit(IntArraySubscriptExpression *);
        SymbolData *visit(IntArrayType *);
        SymbolData *visit(IntLiteral *);
        SymbolData *visit(IntType *);
        SymbolData *visit(MainClassDeclaration *);
        SymbolData *visit(MethodDeclaration *);
        SymbolData *visit(MethodDeclarationList *);
        SymbolData *visit(NewIntArrayExpression *);
        SymbolData *visit(NewObjectExpression *);
        SymbolData *visit(ParameterDeclaration *);
        SymbolData *visit(ParameterDeclarationList *);
        SymbolData *visit(PrintStatement *);
        SymbolData *visit(ProgramDeclaration *);
        SymbolData *visit(StatementList *);
        SymbolData *visit(ThisExpression *);
        SymbolData *visit(UnaryBooleanExpression *);
        SymbolData *visit(VariableDeclaration *);
        SymbolData *visit(VariableDeclarationList *);
        SymbolData *visit(WhileStatement *);

      private:
        // TODO: should be returned by methods
        std::map<std::string, void *> _classes;
    };
  }
}

#endif
