#ifndef KOMPIS_AST_LIST_HPP
#define KOMPIS_AST_LIST_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;
    class VisitorData;

    template <class T>
    class List
    {
      public:
        virtual ~List() {}
        virtual VisitorData *accept(Visitor *) = 0;

        std::list<T *> _list;
    };
  }
}

#endif
