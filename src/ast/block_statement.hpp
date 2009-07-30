#ifndef KOMPIS_AST_BLOCK_STATEMENT_HPP
#define KOMPIS_AST_BLOCK_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class StatementList;
    class Visitor;

    class BlockStatement : public Statement
    {
      public:
        BlockStatement(StatementList *statements)
          : _statements(statements) {}

        void accept(Visitor *visitor);

      //private:
        StatementList *_statements;
    };
  }
}

#endif
