#ifndef KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP
#define KOMPIS_IRT_CONDITIONAL_JUMP_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class Expression;
    class LabelStatement;

    class ConditionalJumpStatement : public Statement
    {
      public:
        enum Operation
        {
          EQ,
          NE,
          LT,
          LE,
          GT,
          GE,
        };

        ConditionalJumpStatement(Operation op,
                                 Expression *lhs,
                                 Expression *rhs,
                                 LabelStatement *then_label,
                                 LabelStatement *else_label)
          : _op(op),
            _lhs(lhs),
            _rhs(rhs),
            _then_label(then_label),
            _else_label(else_label) {}

      private:
        Operation _op;
        Expression *_lhs, *_rhs;
        LabelStatement *_then_label, *_else_label;
    };
  }
}

#endif
