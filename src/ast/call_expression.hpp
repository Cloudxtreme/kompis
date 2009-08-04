#ifndef KOMPIS_AST_CALL_EXPRESSION_HPP
#define KOMPIS_AST_CALL_EXPRESSION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class ExpressionList;
    class Identifier;
    class Visitor;
    class VisitorData;

    class CallExpression : public Node
    {
      public:
        CallExpression(Expression *self,
                       Identifier *method_name,
                       ExpressionList *args,
                       int line_num = 0)
          : Node(line_num),
            _self(self),
            _method_name(method_name),
            _args(args) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_self;
        Identifier *_method_name;
        ExpressionList *_args;
    };
  }
}

#endif
