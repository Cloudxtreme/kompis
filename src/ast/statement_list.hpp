#ifndef KOMPIS_AST_STATEMENT_LIST_HPP
#define KOMPIS_AST_STATEMENT_LIST_HPP

#include "ast/list.hpp"
#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class StatementList : public List<Statement>, public Statement
    {
      public:
        StatementList(int line_num = 0)
          : Statement(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
