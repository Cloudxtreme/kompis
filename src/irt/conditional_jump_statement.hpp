#ifndef KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP
#define KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    namespace rel
    {
      enum Relation
      {
        EQ, // equal
        NE, // not equal
        LT, // less than
        LE, // less than or equal
        GT, // greater than
        GE, // greater than or equal
      };
    }

    class Expression;
    class LabelStatement;

    class ConditionalJumpStatement : public Statement
    {
      public:
        ConditionalJumpStatement(rel::Relation rel,
                                 Expression &left,
                                 Expression &right,
                                 LabelStatement &then_label,
                                 LabelStatement &else_label)
          : _rel(rel),
            _left(left),
            _right(right),
            _then_label(then_label),
            _else_label(else_label) {}

      private:
        rel::Relation _rel;
        Expression &_left, &_right;
        LabelStatement &_then_label, &_else_label;
    };
  }
}

#endif
