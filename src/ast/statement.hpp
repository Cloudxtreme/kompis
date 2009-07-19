#ifndef KOMPIS_AST_STATEMENT_HPP
#define KOMPIS_AST_STATEMENT_HPP

#include "ast/node.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class Statement : public Node
    {
      public:
        virtual ~Statement() {}
        virtual void accept(Visitor &) = 0;
    };
  }
}

#endif
