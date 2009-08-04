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
    class VisitorData;

    class ParameterDeclaration : public Node
    {
      public:
        ParameterDeclaration(int line_num, Type *type, Identifier *name)
          : Node(line_num), _type(type), _name(name) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Type *_type;
        Identifier *_name;
    };
  }
}

#endif
