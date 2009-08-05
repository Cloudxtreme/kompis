#ifndef KOMPIS_AST_CALL_EXPRESSION_HPP
#define KOMPIS_AST_CALL_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class ExpressionList;
    class Identifier;
    class Visitor;
    class VisitorData;

    class CallExpression : public Expression
    {
      public:
        CallExpression(Expression *self,
                       Identifier *method_name,
                       ExpressionList *args,
                       int line_num = 0)
          : Expression(line_num),
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
