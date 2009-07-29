#ifndef KOMPIS_AST_BLOCK_STATEMENT_HPP
#define KOMPIS_AST_BLOCK_STATEMENT_HPP

#include <list>
#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class BlockStatement : public Statement
    {
      public:
        BlockStatement(std::list<Statement *> *statements) : _statements(statements) {}

        void accept(Visitor *visitor);

      //private:
        std::list<Statement *> *_statements;
    };
  }
}

#endif
