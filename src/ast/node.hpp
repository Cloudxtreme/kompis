#ifndef KOMPIS_AST_NODE_HPP
#define KOMPIS_AST_NODE_HPP

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class Node
    {
      public:
        virtual ~Node() {}
        virtual VisitorData *accept(Visitor *) = 0;
    };
  }
}

#endif
