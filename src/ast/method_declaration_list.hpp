#ifndef KOMPIS_AST_METHOD_DECLARATION_LIST_HPP
#define KOMPIS_AST_METHOD_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class MethodDeclaration;
    class Visitor;

    class MethodDeclarationList : public List<MethodDeclaration>
    {
      public:
        void accept(Visitor *);
    };
  }
}

#endif
