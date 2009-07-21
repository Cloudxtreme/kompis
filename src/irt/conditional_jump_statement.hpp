#ifndef KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP
#define KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class Expression;
    class LabelStatement;

    enum RelationalOperator
    {
      EQ, // ==
      NE, // !=
      LT, // <
      LE, // <=
      GT, // >
      GE, // >=
    };

    class ConditionalJumpStatement : public Statement
    {
      public:
        ConditionalJumpStatement(RelationalOperator relation, Expression &left, Expression &right, LabelStatement &then_label, LabelStatement &else_label)
          : _relation(relation), _left(left), _right(right), _then_label(then_label), _else_label(else_label) {}

      private:
        RelationalOperator _relation;
        Expression &_left, &_right;
        LabelStatement &_then_label, &_else_label;
    };
  }
}

#endif
