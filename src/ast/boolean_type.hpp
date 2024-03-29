#ifndef KOMPIS_AST_BOOLEAN_TYPE_HPP
#define KOMPIS_AST_BOOLEAN_TYPE_HPP

#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class BooleanType : public Type
    {
      public:
        BooleanType(int line_num = 0)
          : Type(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
