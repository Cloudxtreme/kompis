#ifndef KOMPIS_AST_EXPRESSION_HPP
#define KOMPIS_AST_EXPRESSION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class Expression : public Node
    {
      public:
        Expression(int line_num = 0)
          : Node(line_num) {}

        virtual ~Expression() {}

        virtual VisitorData *accept(Visitor *) = 0;
    };
  }
}

#endif
