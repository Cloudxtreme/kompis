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
    class VisitorData;

    class VariableDeclaration : public Node
    {
      public:
        VariableDeclaration(Type *type,
                            Identifier *name,
                            int line_num = 0)
          : Node(line_num),
            _type(type),
            _name(name) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Type *_type;
        Identifier *_name;
    };
  }
}

#endif
