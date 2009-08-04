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
        AssignmentStatement(int line_num, Identifier *id, Expression *expr)
          : Statement(line_num), _id(id), _expr(expr) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Identifier *_id;
        Expression *_expr;
    };
  }
}

#endif
