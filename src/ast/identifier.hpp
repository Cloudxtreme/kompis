#ifndef KOMPIS_AST_IDENTIFIER_HPP
#define KOMPIS_AST_IDENTIFIER_HPP

#include <string>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    class Identifier : public Node
    {
      public:
        Identifier(char *name) : _name(name) {}

        void accept(Visitor &visitor);

      //private:
        std::string _name;
    };
  }
}

#endif
