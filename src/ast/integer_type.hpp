#ifndef KOMPIS_AST_INTEGER_TYPE_HPP
#define KOMPIS_AST_INTEGER_TYPE_HPP

#include <string>
#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IntegerType : public Type
    {
      public:
        IntegerType(int line_num)
          : Type(line_num) {}

        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
