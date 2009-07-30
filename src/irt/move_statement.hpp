#ifndef KOMPIS_IRT_MOVE_STATEMENT_HPP
#define KOMPIS_IRT_MOVE_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class Expression;

    class MoveStatement : public Statement
    {
      public:
        MoveStatement(Expression &dst, Expression &src)
          : _dst(dst), _src(src) {}

      private:
        Expression &_dst, &_src;
    };
  }
}

#endif
