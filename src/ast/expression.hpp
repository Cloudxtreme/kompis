#ifndef KOMPIS_AST_EXPRESSION_HPP
#define KOMPIS_AST_EXPRESSION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class Expression : public Node
    {
      public:
        virtual ~Expression() {}
        virtual void accept(Visitor *) = 0;
    };
  }
}

#endif
