#include "ast/ast.hpp"
#include "sema/sema.hpp"
#include "util/error.hpp"

namespace kompis
{
  using namespace util;

  namespace sema
  {
    SymbolData *SymbolTableBuilder::visit(AssignmentStatement *x)
    {
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryBooleanExpression *x)
    {
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryIntExpression *x)
    {
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BlockStatement *x)
    {
      x->_statements->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanLiteral *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanType *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(CallExpression *x)
    {
      x->_self->accept(this);
      x->_method_name->accept(this);
      x->_args->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclaration *x)
    {
      x->_name->accept(this);
      x->_vars->accept(this);
      x->_methods->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclarationList *x)
    {
      for(std::list<ClassDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ComparisonExpression *x)
    {
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ExpressionList *x)
    {
      for(std::list<Expression *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(Identifier *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierExpression *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierType *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IfElseStatement *x)
    {
      x->_condition->accept(this);
      x->_then_statement->accept(this);
      x->_else_statement->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayAssignmentStatement *x)
    {
      x->_id->accept(this);
      x->_index->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayLengthExpression *x)
    {
      x->_array->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArraySubscriptExpression *x)
    {
      x->_array->accept(this);
      x->_index->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayType *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntLiteral *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntType *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MainClassDeclaration *x)
    {
      x->_statement->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MethodDeclaration *x)
    {
      x->_return_type->accept(this);
      x->_name->accept(this);
      x->_params->accept(this);
      x->_vars->accept(this);
      x->_statements->accept(this);
      x->_return_expr->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MethodDeclarationList *x)
    {
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewIntArrayExpression *x)
    {
      x->_count->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewObjectExpression *x)
    {
      x->_class_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclaration *x)
    {
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclarationList *x)
    {
      for(std::list<ParameterDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(PrintStatement *x)
    {
      x->_expr->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ProgramDeclaration *x)
    {
      x->_main->accept(this);
      x->_classes->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(StatementList *x)
    {
      for(std::list<Statement *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ThisExpression *x)
    {
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(UnaryBooleanExpression *x)
    {
      x->_expr->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclaration *x)
    {
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclarationList *x)
    {
      for(std::list<VariableDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(WhileStatement *x)
    {
      x->_condition->accept(this);
      x->_statement->accept(this);
      return NULL;
    }
  }
}
