#ifndef KOMPIS_IRT_JUMP_STATEMENT_HPP
#define KOMPIS_IRT_JUMP_STATEMENT_HPP

#include <list>
#include "irt/statement.hpp"

namespace kompis
{
  namespace irt
  {
    class Expression;
    class LabelStatement;

    class JumpStatement : public Statement
    {
      public:
        //JumpStatement(LabelStatement &label) {}
        //JumpStatement(Expression &_address, std::list<LabelStatement *> possible_labels) {}

      private:
        //Expression &_address;
        //std::list<LabelStatement *> _possible_labels;
    };
  }
}

#endif
