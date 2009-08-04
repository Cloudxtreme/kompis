#ifndef KOMPIS_AST_IF_ELSE_STATEMENT_HPP
#define KOMPIS_AST_IF_ELSE_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class IfElseStatement : public Statement
    {
      public:
        IfElseStatement(Expression *condition,
                        Statement *then_statement,
                        Statement *else_statement,
                        int line_num = 0)
          : Statement(line_num),
            _condition(condition),
            _then_statement(then_statement),
            _else_statement(else_statement) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_condition;
        Statement *_then_statement, *_else_statement;
    };
  }
}

#endif
