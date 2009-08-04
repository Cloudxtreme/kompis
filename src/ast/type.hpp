#ifndef KOMPIS_AST_TYPE_HPP
#define KOMPIS_AST_TYPE_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class Type : public Node
    {
      public:
        virtual ~Type() {}
        virtual VisitorData *accept(Visitor *) = 0;
    };
  }
}

#endif
