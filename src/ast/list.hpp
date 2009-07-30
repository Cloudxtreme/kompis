#ifndef KOMPIS_AST_LIST_HPP
#define KOMPIS_AST_LIST_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Visitor;

    template <class T>
    class List
    {
      public:
        virtual ~List() {}
        virtual void accept(Visitor *) = 0;

        std::list<T *> _list;
    };
  }
}

#endif
