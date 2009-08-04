#ifndef KOMPIS_AST_STATEMENT_HPP
#define KOMPIS_AST_STATEMENT_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class Statement : public Node
    {
      public:
        Statement(int line_num = 0)
          : Node(line_num) {}

        virtual ~Statement() {}

        virtual VisitorData *accept(Visitor *) = 0;
    };
  }
}

#endif
