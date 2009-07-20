#ifndef KOMPIS_AST_NEW_OBJECT_EXPRESSION_HPP
#define KOMPIS_AST_NEW_OBJECT_EXPRESSION_HPP

#include "ast/expression.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class Visitor;

    class NewObjectExpression : public Expression
    {
      public:
        NewObjectExpression(Identifier &id) : _id(id) {}

        void accept(Visitor &visitor);

      //private:
        Identifier &_id;
    };
  }
}

#endif