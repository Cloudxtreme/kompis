#ifndef KOMPIS_AST_VARIABLE_DECLARATION_LIST_HPP
#define KOMPIS_AST_VARIABLE_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class VariableDeclaration;
    class Visitor;
    class VisitorData;

    class VariableDeclarationList : public List<VariableDeclaration>
    {
      public:
        VisitorData *accept(Visitor *);
    };
  }
}

#endif
