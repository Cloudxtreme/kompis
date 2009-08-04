#ifndef KOMPIS_AST_CLASS_DECLARATION_LIST_HPP
#define KOMPIS_AST_CLASS_DECLARATION_LIST_HPP

#include "ast/list.hpp"

namespace kompis
{
  namespace ast
  {
    class ClassDeclaration;
    class Visitor;
    class VisitorData;

    class ClassDeclarationList : public List<ClassDeclaration>
    {
      public:
        VisitorData *accept(Visitor *);
    };
  }
}

#endif
