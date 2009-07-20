#ifndef KOMPIS_AST_CALL_EXPRESSION_HPP
#define KOMPIS_AST_CALL_EXPRESSION_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;

    class CallExpression : public Node
    {
      public:
        CallExpression(Expression &self, Identifier &id, std::list<Expression *> args) : _self(self), _id(id), _args(args) {}

        void accept(Visitor &visitor);

      //private:
        Expression &_self;
        Identifier &_id;
        std::list<Expression *> _args;
    };
  }
}

#endif
