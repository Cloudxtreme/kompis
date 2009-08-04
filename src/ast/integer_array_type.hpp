#ifndef KOMPIS_AST_INTEGER_ARRAY_TYPE_HPP
#define KOMPIS_AST_INTEGER_ARRAY_TYPE_HPP

#include <string>
#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntegerArrayType : public Type
    {
      public:
        IntegerArrayType(int line_num = 0)
          : Type(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
