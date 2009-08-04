#ifndef KOMPIS_AST_IDENTIFIER_TYPE_HPP
#define KOMPIS_AST_IDENTIFIER_TYPE_HPP

#include <string>
#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class IdentifierType : public Type
    {
      public:
        IdentifierType(const char *name,
                       int line_num = 0)
          : Type(line_num),
            _name(name) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
