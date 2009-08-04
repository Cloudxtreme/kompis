#ifndef KOMPIS_AST_IF_THEN_ELSE_STATEMENT_HPP
#define KOMPIS_AST_IF_THEN_ELSE_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Visitor;
    class VisitorData;

    class IfThenElseStatement : public Statement
    {
      public:
        IfThenElseStatement(Expression *pred,
                            Statement *then_statement,
                            Statement *else_statement)
          : _pred(pred),
            _then_statement(then_statement),
            _else_statement(else_statement) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Expression *_pred;
        Statement *_then_statement, *_else_statement;
    };
  }
}

#endif
