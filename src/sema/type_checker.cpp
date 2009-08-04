#include "sema/type_checker.hpp"
#include "ast/ast.hpp"
#include "util/error.hpp"

namespace kompis
{
  using namespace util;

  namespace sema
  {
    TypeData *TypeChecker::visit(AdditionExpression *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '+' not int");
        return new TypeData(type::T_ERROR);
      }
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '+' not int");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_INT);
    }

    TypeData *TypeChecker::visit(AssignmentStatement *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_id->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_expr->accept(this));
      if(l->_type != r->_type)
        error("", x->_line_num, "type", "lhs and rhs of '=' of different type");
      return NULL;
    }

    TypeData *TypeChecker::visit(BlockStatement *x)
    {
      x->_statements->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(BooleanLiteral *x)
    {
      return new TypeData(type::T_BOOLEAN);
    }

    TypeData *TypeChecker::visit(BooleanType *x)
    {
      return NULL;
    }

    TypeData *TypeChecker::visit(CallExpression *x)
    {
      // TODO
      x->_self->accept(this);
      x->_method_name->accept(this);
      x->_args->accept(this);
      return new TypeData(type::T_INT);
    }

    TypeData *TypeChecker::visit(ClassDeclaration *x)
    {
      x->_name->accept(this);
      x->_vars->accept(this);
      x->_methods->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(ClassDeclarationList *x)
    {
      for(std::list<ClassDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(ConjunctionExpression *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(l->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "lhs of '&&' not boolean");
        return new TypeData(type::T_ERROR);
      }
      if(r->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "rhs of '&&' not boolean");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_BOOLEAN);
    }

    TypeData *TypeChecker::visit(ExpressionList *x)
    {
      for(std::list<Expression *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(Identifier *x)
    {
      return new TypeData(type::T_INT); // TODO
    }

    TypeData *TypeChecker::visit(IdentifierExpression *x)
    {
      return new TypeData(type::T_INT); // TODO
    }

    TypeData *TypeChecker::visit(IdentifierType *x)
    {
      return new TypeData(type::T_INT); // TODO
    }

    TypeData *TypeChecker::visit(IfThenElseStatement *x)
    {
      // TODO
      x->_pred->accept(this);
      x->_then_statement->accept(this);
      x->_else_statement->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(IntegerLiteral *x)
    {
      return new TypeData(type::T_INT);
    }

    TypeData *TypeChecker::visit(IntegerType *x)
    {
      return NULL;
    }

    TypeData *TypeChecker::visit(LessThanExpression *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '<' not int");
        return new TypeData(type::T_ERROR);
      }
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '<' not int");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_BOOLEAN);
    }

    TypeData *TypeChecker::visit(MainClassDeclaration *x)
    {
      x->_statement->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(MethodDeclaration *x)
    {
      x->_return_type->accept(this);
      x->_name->accept(this);
      x->_params->accept(this);
      x->_vars->accept(this);
      x->_statements->accept(this);
      x->_return_expr->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(MethodDeclarationList *x)
    {
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(MultiplicationExpression *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '*' not int");
        return new TypeData(type::T_ERROR);
      }
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '*' not int");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_INT);
    }

    TypeData *TypeChecker::visit(NegationExpression *x)
    {
      TypeData *r = static_cast<TypeData *>(x->_expr->accept(this));
      if(r->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "rhs of '!' not boolean");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_BOOLEAN);
    }

    TypeData *TypeChecker::visit(NewObjectExpression *x)
    {
      // TODO
      x->_class_name->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(ParameterDeclaration *x)
    {
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(ParameterDeclarationList *x)
    {
      for(std::list<ParameterDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(PrintStatement *x)
    {
      TypeData *e = static_cast<TypeData *>(x->_expr->accept(this));
      if(e->_type != type::T_INT)
        error("", x->_line_num, "type", "argument to 'System.out.println' not int");
      return NULL;
    }

    TypeData *TypeChecker::visit(ProgramDeclaration *x)
    {
      x->_main->accept(this);
      x->_classes->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(StatementList *x)
    {
      for(std::list<Statement *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(SubtractionExpression *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '-' not int");
        return new TypeData(type::T_ERROR);
      }
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '-' not int");
        return new TypeData(type::T_ERROR);
      }
      return new TypeData(type::T_INT);
    }

    TypeData *TypeChecker::visit(ThisExpression *x)
    {
      return NULL;
    }

    TypeData *TypeChecker::visit(VariableDeclaration *x)
    {
      x->_type->accept(this);
      x->_name->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(VariableDeclarationList *x)
    {
      for(std::list<VariableDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(WhileDoStatement *x)
    {
      // TODO
      x->_pred->accept(this);
      x->_s->accept(this);
      return NULL;
    }
  }
}
