#ifndef KOMPIS_IRT_ESEQ_EXPRESSION_HPP
#define KOMPIS_IRT_ESEQ_EXPRESSION_HPP

#include "irt/expression.hpp"

namespace kompis
{
  namespace irt
  {
    class Statement;

    class EseqExpression : public Expression
    {
      public:
        EseqExpression(Statement &s, Expression &e)
          : _s(s), _e(e) {}

      private:
        Statement &_s;
        Expression &_e;
    };
  }
}

#endif
