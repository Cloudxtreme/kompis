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
      // nothing
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryBooleanExpression *x)
    {
      // nothing
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryIntExpression *x)
    {
      // nothing
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BlockStatement *x)
    {
      // nothing
      x->_statements->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanLiteral *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanType *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(CallExpression *x)
    {
      // nothing
      x->_self->accept(this);
      x->_method_name->accept(this);
      x->_args->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclaration *x)
    {
      // check unique, create class
      x->_name->accept(this);
      x->_vars->accept(this);
      x->_methods->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclarationList *x)
    {
      // create classes
      for(std::list<ClassDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ComparisonExpression *x)
    {
      // nothing
      x->_lhs->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ExpressionList *x)
    {
      // nothing
      for(std::list<Expression *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(Identifier *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierExpression *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierType *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IfElseStatement *x)
    {
      // nothing
      x->_condition->accept(this);
      x->_then_statement->accept(this);
      x->_else_statement->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayAssignmentStatement *x)
    {
      // nothing
      x->_id->accept(this);
      x->_index->accept(this);
      x->_rhs->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayLengthExpression *x)
    {
      // nothing
      x->_array->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArraySubscriptExpression *x)
    {
      // nothing
      x->_array->accept(this);
      x->_index->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayType *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntLiteral *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntType *x)
    {
      // ?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MainClassDeclaration *x)
    {
      // nothing?
      x->_statement->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MethodDeclaration *x)
    {
      // check unique, create method
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
      // create methods
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewIntArrayExpression *x)
    {
      // nothing
      x->_count->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewObjectExpression *x)
    {
      // nothing
      x->_class_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclaration *x)
    {
      // check unique, return param
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclarationList *x)
    {
      // return params
      for(std::list<ParameterDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(PrintStatement *x)
    {
      // nothing
      x->_expr->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ProgramDeclaration *x)
    {
      // create classes
      x->_main->accept(this);
      x->_classes->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(StatementList *x)
    {
      // nothing
      for(std::list<Statement *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ThisExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(UnaryBooleanExpression *x)
    {
      // nothing
      x->_expr->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclaration *x)
    {
      // check unique, create var
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclarationList *x)
    {
      // create vars
      for(std::list<VariableDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(WhileStatement *x)
    {
      // nothing
      x->_condition->accept(this);
      x->_statement->accept(this);
      return NULL;
    }
  }
}
