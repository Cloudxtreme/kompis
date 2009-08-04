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
        AssignmentStatement(Identifier *lhs,
                            Expression *rhs,
                            int line_num = 0)
          : Statement(line_num),
            _lhs(lhs),
            _rhs(rhs) {}

        VisitorData *accept(Visitor *visitor);

        Identifier *_lhs;
        Expression *_rhs;
    };
  }
}

#endif
