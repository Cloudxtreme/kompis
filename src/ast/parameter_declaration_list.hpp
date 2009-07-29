#ifndef KOMPIS_AST_PARAMETER_DECLARATION_LIST_HPP
#define KOMPIS_AST_PARAMETER_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class ParameterDeclaration;
    class Visitor;

    class ParameterDeclarationList : public List<ParameterDeclaration>
    {
      public:
        void accept(Visitor *);
    };
  }
}

#endif
