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
        WhileStatement(Expression *pred,
                       Statement *s,
                       int line_num = 0)
          : Statement(line_num),
            _pred(pred),
            _s(s) {}

        VisitorData *accept(Visitor *visitor);

        Expression *_pred;
        Statement *_s;
    };
  }
}

#endif
