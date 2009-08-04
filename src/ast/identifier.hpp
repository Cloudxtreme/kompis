#ifndef KOMPIS_AST_IDENTIFIER_HPP
#define KOMPIS_AST_IDENTIFIER_HPP

#include <string>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    class Identifier : public Node
    {
      public:
        Identifier(const char *name)
          : _name(name) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
