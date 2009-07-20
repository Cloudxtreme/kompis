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
        VariableDeclaration(Type &type, Identifier &id) : _type(type), _id(id) {}

        void accept(Visitor &visitor);

      //private:
        Type &_type;
        Identifier &_id;
    };
  }
}

#endif
