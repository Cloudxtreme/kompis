#ifndef KOMPIS_AST_NODE_HPP
#define KOMPIS_AST_NODE_HPP

#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class Node
    {
      public:
        virtual ~Node() {}
        virtual void accept(Visitor *) = 0;
    };
  }
}

#endif
