#ifndef KOMPIS_AST_METHOD_DECLARATION_HPP
#define KOMPIS_AST_METHOD_DECLARATION_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class ParameterDeclaration;
    class Statement;
    class Type;
    class VariableDeclaration;
    class Visitor;

    class MethodDeclaration : public Node
    {
      public:
        MethodDeclaration(Type &return_type, Identifier &id, std::list<ParameterDeclaration *> params, std::list<VariableDeclaration *> vars, std::list<Statement *> statements, Expression &return_expr) : _return_type(return_type), _id(id), _params(params), _vars(vars), _statements(statements), _return_expr(return_expr) {}

        void accept(Visitor &);

      //private:
        Type &_return_type;
        Identifier &_id;
        std::list<ParameterDeclaration *> _params;
        std::list<VariableDeclaration *> _vars;
        std::list<Statement *> _statements;
        Expression &_return_expr;
    };
  }
}

#endif
