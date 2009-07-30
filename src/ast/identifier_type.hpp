#ifndef KOMPIS_AST_IDENTIFIER_TYPE_HPP
#define KOMPIS_AST_IDENTIFIER_TYPE_HPP

#include <string>
#include "ast/type.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class IdentifierType : public Type
    {
      public:
        IdentifierType(char *name)
          : _name(name) {}

        void accept(Visitor *visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
