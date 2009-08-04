#ifndef KOMPIS_AST_METHOD_DECLARATION_HPP
#define KOMPIS_AST_METHOD_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class ParameterDeclarationList;
    class StatementList;
    class Type;
    class VariableDeclarationList;
    class Visitor;
    class VisitorData;

    class MethodDeclaration : public Node
    {
      public:
        MethodDeclaration(Type *return_type,
                          Identifier *name,
                          ParameterDeclarationList *params,
                          VariableDeclarationList *vars,
                          StatementList *statements,
                          Expression *return_expr)
          : _return_type(return_type),
            _name(name),
            _params(params),
            _vars(vars),
            _statements(statements),
            _return_expr(return_expr) {}

        VisitorData *accept(Visitor *);

      //private:
        Type *_return_type;
        Identifier *_name;
        ParameterDeclarationList *_params;
        VariableDeclarationList *_vars;
        StatementList *_statements;
        Expression *_return_expr;
    };
  }
}

#endif
