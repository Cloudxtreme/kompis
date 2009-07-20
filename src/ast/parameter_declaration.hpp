#ifndef KOMPIS_AST_PARAMETER_DECLARATION_HPP
#define KOMPIS_AST_PARAMETER_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class Type;
    class Visitor;

    class ParameterDeclaration : public Node
    {
      public:
        ParameterDeclaration(Type &type, Identifier &id) : _type(type), _id(id) {}

        void accept(Visitor &visitor);

      //private:
        Type &_type;
        Identifier &_id;
    };
  }
}

#endif