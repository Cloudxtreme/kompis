#include "ast/pretty_printer.hpp"
#include "ast/ast.hpp"

namespace kompis
{
  namespace ast
  {
    void PrettyPrinter::indent()
    {
      for(int i = 0; i < _indentation; ++i)
        _out << '\t';
    }

    void PrettyPrinter::visit(AdditionExpression *x)
    {
      indent();
      ++_indentation;
      _out << "+\n";
      x->_left->accept(this);
      x->_right->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(AssignmentStatement *x)
    {
      indent();
      ++_indentation;
      _out << "=\n";
      x->_id->accept(this);
      x->_expr->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(BlockStatement *x)
    {
      indent();
      ++_indentation;
      _out << "block\n";
      x->_statements->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(BooleanLiteral *x)
    {
      indent();
      ++_indentation;
      _out << (x->_value ? "true" : "false") << "\n";
      --_indentation;
    }

    void PrettyPrinter::visit(BooleanType *x)
    {
      indent();
      ++_indentation;
      _out << "Boolean\n";
      --_indentation;
    }

    void PrettyPrinter::visit(CallExpression *x)
    {
      indent();
      ++_indentation;
      _out << "call\n";
      x->_self->accept(this);
      x->_method_name->accept(this);
      x->_args->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ClassDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "class\n";
      x->_name->accept(this);
      x->_vars->accept(this);
      x->_methods->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ClassDeclarationList *x)
    {
      indent();
      ++_indentation;
      _out << "class_declaration_list\n";
      for(std::list<ClassDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ConjunctionExpression *x)
    {
      indent();
      ++_indentation;
      _out << "&&\n";
      x->_left->accept(this);
      x->_right->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ExpressionList *x)
    {
      indent();
      ++_indentation;
      _out << "expression_list\n";
      for(std::list<Expression *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(Identifier *x)
    {
      indent();
      ++_indentation;
      _out << x->_name << "\n";
      --_indentation;
    }

    void PrettyPrinter::visit(IdentifierExpression *x)
    {
      indent();
      ++_indentation;
      _out << x->_name << "\n";
      --_indentation;
    }

    void PrettyPrinter::visit(IdentifierType *x)
    {
      indent();
      ++_indentation;
      _out << x->_name << "\n";
      --_indentation;
    }

    void PrettyPrinter::visit(IfThenElseStatement *x)
    {
      indent();
      ++_indentation;
      _out << "if\n";
      x->_pred->accept(this);
      x->_then_statement->accept(this);
      x->_else_statement->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(IntegerLiteral *x)
    {
      indent();
      ++_indentation;
      _out << x->_value << "\n";
      --_indentation;
    }

    void PrettyPrinter::visit(IntegerType *x)
    {
      indent();
      ++_indentation;
      _out << "Integer\n";
      --_indentation;
    }

    void PrettyPrinter::visit(LessThanExpression *x)
    {
      indent();
      ++_indentation;
      _out << "<\n";
      x->_left->accept(this);
      x->_right->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(MainClassDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "main\n";
      x->_statement->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(MethodDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "method\n";
      x->_return_type->accept(this);
      x->_name->accept(this);
      x->_params->accept(this);
      x->_vars->accept(this);
      x->_statements->accept(this);
      x->_return_expr->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(MethodDeclarationList *x)
    {
      indent();
      ++_indentation;
      _out << "method_declaration_list\n";
      for(std::list<MethodDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(MultiplicationExpression *x)
    {
      indent();
      ++_indentation;
      _out << "*\n";
      x->_left->accept(this);
      x->_right->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(NegationExpression *x)
    {
      indent();
      ++_indentation;
      _out << "!\n";
      x->_expr->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(NewObjectExpression *x)
    {
      indent();
      ++_indentation;
      _out << "new\n";
      x->_class_name->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ParameterDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "parameter\n";
      x->_type->accept(this);
      x->_name->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ParameterDeclarationList *x)
    {
      indent();
      ++_indentation;
      _out << "parameter_declaration_list\n";
      for(std::list<ParameterDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(PrintStatement *x)
    {
      indent();
      ++_indentation;
      _out << "print\n";
      x->_expr->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ProgramDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "program\n";
      x->_main->accept(this);
      x->_classes->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(StatementList *x)
    {
      indent();
      ++_indentation;
      _out << "statement_list\n";
      for(std::list<Statement *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(SubtractionExpression *x)
    {
      indent();
      ++_indentation;
      _out << "-\n";
      x->_left->accept(this);
      x->_right->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(ThisExpression *x)
    {
      indent();
      ++_indentation;
      _out << "this\n";
      --_indentation;
    }

    void PrettyPrinter::visit(VariableDeclaration *x)
    {
      indent();
      ++_indentation;
      _out << "variable\n";
      x->_type->accept(this);
      x->_name->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(VariableDeclarationList *x)
    {
      indent();
      ++_indentation;
      _out << "variable_declaration_list\n";
      for(std::list<VariableDeclaration *>::iterator i = x->_list.begin(), e = x->_list.end(); i != e; ++i)
        (*i)->accept(this);
      --_indentation;
    }

    void PrettyPrinter::visit(WhileDoStatement *x)
    {
      indent();
      ++_indentation;
      _out << "while\n";
      x->_pred->accept(this);
      x->_s->accept(this);
      --_indentation;
    }
  }
}
