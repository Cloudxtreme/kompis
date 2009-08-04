#ifndef KOMPIS_AST_NEW_OBJECT_EXPRESSION_HPP
#define KOMPIS_AST_NEW_OBJECT_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class Visitor;
    class VisitorData;

    class NewObjectExpression : public Expression
    {
      public:
        NewObjectExpression(Identifier *class_name,
                            int line_num = 0)
          : Expression(line_num),
            _class_name(class_name) {}

        VisitorData *accept(Visitor *visitor);

        Identifier *_class_name;
    };
  }
}

#endif
