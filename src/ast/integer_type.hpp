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
        VisitorData *accept(Visitor *visitor);
    };
  }
}

#endif
