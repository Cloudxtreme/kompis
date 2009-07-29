#ifndef KOMPIS_AST_STATEMENT_LIST_HPP
#define KOMPIS_AST_STATEMENT_LIST_HPP

#include "ast/list.hpp"
#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class StatementList : public List<Statement>, public Statement
    {
      public:
        void accept(Visitor *visitor);
    };
  }
}

#endif
