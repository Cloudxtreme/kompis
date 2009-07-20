#ifndef KOMPIS_AST_CLASS_DECLARATION_HPP
#define KOMPIS_AST_CLASS_DECLARATION_HPP

#include <list>
#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class MethodDeclaration;
    class VariableDeclaration;
    class Visitor;

    class ClassDeclaration : public Node
    {
      public:
        ClassDeclaration(Identifier &id, std::list<VariableDeclaration *> vars, std::list<MethodDeclaration *> methods) : _id(id), _vars(vars), _methods(methods) {}

        void accept(Visitor &);

      //private:
        Identifier &_id;
        std::list<VariableDeclaration *> _vars;
        std::list<MethodDeclaration *> _methods;
    };
  }
}

#endif
