#ifndef KOMPIS_AST_ARRAY_ASSIGNMENT_STATEMENT_HPP
#define KOMPIS_AST_ARRAY_ASSIGNMENT_STATEMENT_HPP

#include "ast/statement.hpp"

namespace kompis
{
  namespace ast
  {
    class Expression;
    class Identifier;
    class Visitor;
    class VisitorData;

    class ArrayAssignmentStatement : public Statement
    {
      public:
        ArrayAssignmentStatement(Identifier *id,
                                 Expression *index,
                                 Expression *value,
                                 int line_num = 0)
          : Statement(line_num),
            _id(id),
            _index(index),
            _value(value) {}

        VisitorData *accept(Visitor *visitor);

      //private:
        Identifier *_id;
        Expression *_index;
        Expression *_value;
    };
  }
}

#endif
