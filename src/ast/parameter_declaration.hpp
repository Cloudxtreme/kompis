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
        ParameterDeclaration(Type *type,
                             Identifier *name,
                             int line_num = 0)
          : Node(line_num),
            _type(type),
            _name(name) {}

        VisitorData *accept(Visitor *visitor);

        Type *_type;
        Identifier *_name;
    };
  }
}

#endif
