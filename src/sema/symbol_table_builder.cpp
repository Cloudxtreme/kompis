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
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryBooleanExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BinaryIntExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BlockStatement *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanLiteral *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(BooleanType *x)
    {
      // TODO: return boolean type
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(CallExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclaration *x)
    {
      // TODO: report error if class name in use
      // TODO: return class data

      x->_name->accept(this);
      x->_vars->accept(this);
      x->_methods->accept(this);

      if(_classes.find(x->_name->_name) != _classes.end())
        error("", x->_line_num, "symbol", "class name already in use");
      else
        _classes.insert(std::make_pair(x->_name->_name, static_cast<void *>(NULL))); // TODO: create class data

      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ClassDeclarationList *x)
    {
      // TODO: return classes
      for(std::list<ClassDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ComparisonExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ExpressionList *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(Identifier *x)
    {
      // TODO: return something?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierExpression *x)
    {
      // TODO: return something?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IdentifierType *x)
    {
      // TODO: return something?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IfElseStatement *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayAssignmentStatement *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayLengthExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArraySubscriptExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntArrayType *x)
    {
      // TODO: return int array type?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntLiteral *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(IntType *x)
    {
      // TODO: return int type?
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MainClassDeclaration *x)
    {
      // TODO: nothing? means that another class may have same name as main class, because main class is not a real class
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(MethodDeclaration *x)
    {
      // TODO: report error if method name in use in scope
      // TODO: return method data
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
      // TODO: return methods
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewIntArrayExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(NewObjectExpression *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclaration *x)
    {
      // TODO: report error if param name in use in scope
      // TODO: return param data (same as variable data, right?)
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ParameterDeclarationList *x)
    {
      // TODO: return params
      for(std::list<ParameterDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(PrintStatement *x)
    {
      // nothing
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(ProgramDeclaration *x)
    {
      // TODO: store class data somewhere
      x->_main->accept(this);
      x->_classes->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(StatementList *x)
    {
      // nothing
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
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclaration *x)
    {
      // TODO: report error if variable name in use in scope
      // TODO: return variable data
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(VariableDeclarationList *x)
    {
      // TODO: return variables
      for(std::list<VariableDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    SymbolData *SymbolTableBuilder::visit(WhileStatement *x)
    {
      // nothing
      return NULL;
    }
  }
}
