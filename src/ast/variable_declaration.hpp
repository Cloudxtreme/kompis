#ifndef KOMPIS_AST_VARIABLE_DECLARATION_HPP
#define KOMPIS_AST_VARIABLE_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class Type;
    class Visitor;

    class VariableDeclaration : public Node
    {
      public:
        VariableDeclaration(Type *type, Identifier *name)
          : _type(type), _name(name) {}

        void accept(Visitor *visitor);

      //private:
        Type *_type;
        Identifier *_name;
    };
  }
}

#endif
