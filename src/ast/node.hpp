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
        Node(int line_num = 0)
          : _line_num(line_num) {}

        virtual ~Node() {}

        virtual VisitorData *accept(Visitor *) = 0;

        int _line_num;
    };
  }
}

#endif
