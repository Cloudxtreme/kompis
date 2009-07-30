#ifndef KOMPIS_IRT_SEQ_STATEMENT_HPP
#define KOMPIS_IRT_SEQ_STATEMENT_HPP

#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class SeqStatement : public Statement
    {
      public:
        SeqStatement(Statement &s1, Statement &s2)
          : _s1(s1), _s2(s2) {}

      private:
        Statement &_s1, &_s2;
    };
  }
}

#endif
