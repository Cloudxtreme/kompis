#ifndef KOMPIS_AST_PARAMETER_DECLARATION_LIST_HPP
#define KOMPIS_AST_PARAMETER_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class ParameterDeclaration;
    class Visitor;
    class VisitorData;

    class ParameterDeclarationList : public List<ParameterDeclaration>
    {
      public:
        VisitorData *accept(Visitor *);
    };
  }
}

#endif
