#ifndef KOMPIS_AST_ASSIGNMENT_STATEMENT_HPP
#define KOMPIS_AST_ASSIGNMENT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;
    class VisitorData;

    class AssignmentStatement : public Statement
    {
      public:
        AssignmentStatement(Identifier *id,
                            Expression *expr,
                            int line_num = 0)
          : Statement(line_num),
            _id(id),
            _expr(expr) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Identifier *_id;
        Expression *_expr;
    };
  }
}

#endif
