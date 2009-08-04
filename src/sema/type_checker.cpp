#include "sema/type_checker.hpp"
#include "ast/ast.hpp"
#include "util/error.hpp"

namespace kompis
{
  using namespace util;

  namespace sema
  {
    TypeData *TypeChecker::visit(ArrayAssignmentStatement *x)
    {
      TypeData *a = static_cast<TypeData *>(x->_id->accept(this));
      if(a->_type != type::T_INT_ARRAY)
        error("", x->_line_num, "type", "lhs of '[]=' not int array");

      TypeData *i = static_cast<TypeData *>(x->_index->accept(this));
      if(i->_type != type::T_INT)
        error("", x->_line_num, "type", "array index not int");

      TypeData *v = static_cast<TypeData *>(x->_value->accept(this));
      if(v->_type != type::T_INT)
        error("", x->_line_num, "type", "rhs of '[]=' not int");

      return NULL;
    }

    TypeData *TypeChecker::visit(ArrayLengthExpression *x)
    {
      type::Type t = type::T_INT;

      TypeData *a = static_cast<TypeData *>(x->_array->accept(this));
      if(a->_type != type::T_INT_ARRAY)
      {
        error("", x->_line_num, "type", "self of 'length' not int array"); // TODO: better error message?
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(ArraySubscriptExpression *x)
    {
      type::Type t = type::T_INT;

      TypeData *a = static_cast<TypeData *>(x->_array->accept(this));
      if(a->_type != type::T_INT_ARRAY)
      {
        error("", x->_line_num, "type", "self of 'length' not int array"); // TODO: better error message?
        t = type::T_ERROR;
      }

      TypeData *i = static_cast<TypeData *>(x->_index->accept(this));
      if(i->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "array index not int");
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(AssignmentStatement *x)
    {
      TypeData *l = static_cast<TypeData *>(x->_id->accept(this));
      TypeData *r = static_cast<TypeData *>(x->_expr->accept(this));
      if(l->_type != r->_type)
        error("", x->_line_num, "type", "lhs and rhs of '=' of different type");
      return NULL;
    }

    TypeData *TypeChecker::visit(BinaryIntExpression *x)
    {
      // TODO: use binop::str

      type::Type t = type::T_INT;

      TypeData *l = static_cast<TypeData *>(x->_lhs->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '+' not int");
        t = type::T_ERROR;
      }

      TypeData *r = static_cast<TypeData *>(x->_rhs->accept(this));
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '+' not int");
        t = type::T_ERROR;
      }

      return new TypeData(t);
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
      type::Type t = type::T_INT; // TODO: use return type from method declaration

      TypeData *s = static_cast<TypeData *>(x->_self->accept(this));
      if(s->_type != type::T_OBJECT)
      {
        error("", x->_line_num, "type", "self of 'call' not object"); // TODO: better error message?
        t = type::T_ERROR;
      }

      x->_method_name->accept(this); // TODO: check defined
      x->_args->accept(this);        // TODO: check each arg against method declaration

      return new TypeData(t);
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
      type::Type t = type::T_BOOLEAN;

      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      if(l->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "lhs of '&&' not boolean");
        t = type::T_ERROR;
      }

      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(r->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "rhs of '&&' not boolean");
        t = type::T_ERROR;
      }

      return new TypeData(t);
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
      return NULL;
    }

    TypeData *TypeChecker::visit(IfThenElseStatement *x)
    {
      TypeData *p = static_cast<TypeData *>(x->_pred->accept(this));
      if(p->_type != type::T_BOOLEAN)
        error("", x->_line_num, "type", "argument to 'if' not boolean");

      x->_then_statement->accept(this);
      x->_else_statement->accept(this);

      return NULL;
    }

    TypeData *TypeChecker::visit(IntegerArrayType *x)
    {
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
      type::Type t = type::T_BOOLEAN;

      TypeData *l = static_cast<TypeData *>(x->_left->accept(this));
      if(l->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "lhs of '<' not int");
        t = type::T_ERROR;
      }

      TypeData *r = static_cast<TypeData *>(x->_right->accept(this));
      if(r->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "rhs of '<' not int");
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(MainClassDeclaration *x)
    {
      x->_statement->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(MethodDeclaration *x)
    {
      x->_return_type->accept(this); // TODO: check defined
      x->_name->accept(this);
      x->_params->accept(this);
      x->_vars->accept(this);
      x->_statements->accept(this);
      x->_return_expr->accept(this); // TODO: check same as return type
      return NULL;
    }

    TypeData *TypeChecker::visit(MethodDeclarationList *x)
    {
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      return NULL;
    }

    TypeData *TypeChecker::visit(NegationExpression *x)
    {
      type::Type t = type::T_BOOLEAN;

      TypeData *r = static_cast<TypeData *>(x->_expr->accept(this));
      if(r->_type != type::T_BOOLEAN)
      {
        error("", x->_line_num, "type", "rhs of '!' not boolean");
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(NewIntegerArrayExpression *x)
    {
      type::Type t = type::T_INT_ARRAY;

      TypeData *c = static_cast<TypeData *>(x->_count->accept(this));
      if(c->_type != type::T_INT)
      {
        error("", x->_line_num, "type", "argument to 'new[]' not int");
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(NewObjectExpression *x)
    {
      // TODO: correct behavior?

      type::Type t = type::T_OBJECT;

      TypeData *c = static_cast<TypeData *>(x->_class_name->accept(this));
      if(c->_type != type::T_OBJECT)
      {
        error("", x->_line_num, "type", "argument to 'new' not object");
        t = type::T_ERROR;
      }

      return new TypeData(t);
    }

    TypeData *TypeChecker::visit(ParameterDeclaration *x)
    {
      x->_type->accept(this); // TODO: check defined
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

    TypeData *TypeChecker::visit(ThisExpression *x)
    {
      // TODO: correct behavior?
      return new TypeData(type::T_OBJECT);
    }

    TypeData *TypeChecker::visit(VariableDeclaration *x)
    {
      x->_type->accept(this); // TODO: check defined
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
      TypeData *p = static_cast<TypeData *>(x->_pred->accept(this));
      if(p->_type != type::T_BOOLEAN)
        error("", x->_line_num, "type", "argument to 'while' not boolean");

      x->_s->accept(this);

      return NULL;
    }
  }
}
