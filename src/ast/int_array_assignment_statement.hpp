#ifndef KOMPIS_AST_ARRAY_ASSIGNMENT_STATEMENT_HPP
#define KOMPIS_AST_ARRAY_ASSIGNMENT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;
    class VisitorData;

    class IntArrayAssignmentStatement : public Statement
    {
      public:
        IntArrayAssignmentStatement(Identifier *id,
                                    Expression *index,
                                    Expression *rhs,
                                    int line_num = 0)
          : Statement(line_num),
            _id(id),
            _index(index),
            _rhs(rhs) {}

        VisitorData *accept(Visitor *visitor);

        Identifier *_id;
        Expression *_index;
        Expression *_rhs;
    };
  }
}

#endif
