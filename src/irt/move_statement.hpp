#ifndef KOMPIS_IRT_MOVE_STATEMENT_HPP
#define KOMPIS_IRT_MOVE_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class MoveStatement : public Statement
    {
      public:
        MoveStatement(Expression &f, Expression &t) : _from(f), _to(t) {}

      private:
        Expression &_from, &_to;
    };
  }
}

#endif
