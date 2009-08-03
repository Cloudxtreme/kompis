#ifndef KOMPIS_AST_INTEGER_ARRAY_TYPE_HPP
#define KOMPIS_AST_INTEGER_ARRAY_TYPE_HPP

#include <string>
#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class IntegerArrayType : public Type
    {
      public:
        void accept(Visitor *visitor);
    };
  }
}

#endif
