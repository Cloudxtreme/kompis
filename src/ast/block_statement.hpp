#ifndef KOMPIS_AST_BLOCK_STATEMENT_HPP
#define KOMPIS_AST_BLOCK_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class StatementList;
    class Visitor;
    class VisitorData;

    class BlockStatement : public Statement
    {
      public:
        BlockStatement(StatementList *statements,
                       int line_num = 0)
          : Statement(line_num),
            _statements(statements) {}

        VisitorData *accept(Visitor *visitor);

        StatementList *_statements;
    };
  }
}

#endif
