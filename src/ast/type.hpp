#ifndef KOMPIS_AST_TYPE_HPP
#define KOMPIS_AST_TYPE_HPP

#include "ast/node.hpp"
#include "ast/visitor.hpp"

namespace kompis
{
  namespace ast
  {
    class Type : public Node
    {
      public:
        virtual ~Type() {}
        virtual void accept(Visitor *) = 0;
    };
  }
}

#endif
