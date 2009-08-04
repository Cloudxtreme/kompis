#ifndef KOMPIS_AST_WHILE_STATEMENT_HPP
#define KOMPIS_AST_WHILE_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class WhileStatement : public Statement
    {
      public:
        WhileStatement(Expression *condition,
                       Statement *statement,
                       int line_num = 0)
          : Statement(line_num),
            _condition(condition),
            _statement(statement) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_condition;
        Statement *_statement;
    };
  }
}

#endif
