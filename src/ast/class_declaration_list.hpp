#ifndef KOMPIS_AST_CLASS_DECLARATION_LIST_HPP
#define KOMPIS_AST_CLASS_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class ClassDeclaration;
    class Visitor;

    class ClassDeclarationList : public List<ClassDeclaration>
    {
      public:
        void accept(Visitor *);
    };
  }
}

#endif
