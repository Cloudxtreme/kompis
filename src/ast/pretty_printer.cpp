#include "ast/pretty_printer.hpp"
#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void PrettyPrinter::visit(AdditionExpression *x)
    {
      _out << "(+ ";
      x->_left->accept(this);
      _out << " ";
      x->_right->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(AssignmentStatement *x)
    {
      _out << "(= ";
      x->_id->accept(this);
      _out << " ";
      x->_expr->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(BlockStatement *x)
    {
      _out << "(block ";
      x->_statements->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(BooleanLiteral *x)
    {
      _out << (x->_value ? "true" : "false");
    }

    void PrettyPrinter::visit(BooleanType *x)
    {
      _out << "Boolean";
    }

    void PrettyPrinter::visit(CallExpression *x)
    {
      _out << "(call ";
      x->_self->accept(this);
      _out << " ";
      x->_method_name->accept(this);
      _out << " ";
      x->_args->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ClassDeclaration *x)
    {
      _out << "(class ";
      x->_name->accept(this);
      _out << " ";
      x->_vars->accept(this);
      _out << " ";
      x->_methods->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ClassDeclarationList *x)
    {
      _out << "(list";
      for(std::list<ClassDeclaration *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(ConjunctionExpression *x)
    {
      _out << "(and ";
      x->_left->accept(this);
      _out << " ";
      x->_right->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ExpressionList *x)
    {
      _out << "(list";
      for(std::list<Expression *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(Identifier *x)
    {
      _out << x->_name;
    }

    void PrettyPrinter::visit(IdentifierExpression *x)
    {
      _out << x->_name;
    }

    void PrettyPrinter::visit(IdentifierType *x)
    {
      _out << x->_name;
    }

    void PrettyPrinter::visit(IfThenElseStatement *x)
    {
      _out << "(if ";
      x->_pred->accept(this);
      _out << " ";
      x->_then_statement->accept(this);
      _out << " ";
      x->_else_statement->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(IntegerLiteral *x)
    {
      _out << x->_value;
    }

    void PrettyPrinter::visit(IntegerType *x)
    {
      _out << "Integer";
    }

    void PrettyPrinter::visit(LessThanExpression *x)
    {
      _out << "(< ";
      x->_left->accept(this);
      _out << " ";
      x->_right->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(MainClassDeclaration *x)
    {
      _out << "(main ";
      x->_name->accept(this);
      _out << " ";
      x->_statement->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(MethodDeclaration *x)
    {
      _out << "(method ";
      x->_return_type->accept(this);
      _out << " ";
      x->_name->accept(this);
      _out << " ";
      x->_params->accept(this);
      _out << " ";
      x->_vars->accept(this);
      _out << " ";
      x->_statements->accept(this);
      _out << " ";
      x->_return_expr->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(MethodDeclarationList *x)
    {
      _out << "(list";
      for(std::list<MethodDeclaration *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(MultiplicationExpression *x)
    {
      _out << "(* ";
      x->_left->accept(this);
      _out << " ";
      x->_right->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(NegationExpression *x)
    {
      _out << "(not ";
      x->_expr->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(NewObjectExpression *x)
    {
      _out << "(new ";
      x->_class_name->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ParameterDeclaration *x)
    {
      _out << "(parameter ";
      x->_type->accept(this);
      _out << " ";
      x->_name->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ParameterDeclarationList *x)
    {
      _out << "(list";
      for(std::list<ParameterDeclaration *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(PrintStatement *x)
    {
      _out << "(print ";
      x->_expr->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ProgramDeclaration *x)
    {
      _out << "(program ";
      x->_main->accept(this);
      _out << " ";
      x->_classes->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(StatementList *x)
    {
      _out << "(list";
      for(std::list<Statement *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(SubtractionExpression *x)
    {
      _out << "(- ";
      x->_left->accept(this);
      _out << " ";
      x->_right->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(ThisExpression *x)
    {
      _out << "this";
    }

    void PrettyPrinter::visit(VariableDeclaration *x)
    {
      _out << "(variable ";
      x->_type->accept(this);
      _out << " ";
      x->_name->accept(this);
      _out << ")";
    }

    void PrettyPrinter::visit(VariableDeclarationList *x)
    {
      _out << "(list";
      for(std::list<VariableDeclaration *>::iterator it = x->_list.begin(); it != x->_list.end(); ++it)
      {
        _out << " ";
        (*it)->accept(this);
      }
      _out << ")";
    }

    void PrettyPrinter::visit(WhileDoStatement *x)
    {
      _out << "(while ";
      x->_pred->accept(this);
      _out << " ";
      x->_s->accept(this);
      _out << ")";
    }
  }
}
