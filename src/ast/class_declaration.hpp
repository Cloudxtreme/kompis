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
        ClassDeclaration(Identifier *name, std::list<VariableDeclaration *> *vars, std::list<MethodDeclaration *> *methods) : _name(name), _vars(vars), _methods(methods) {}

        void accept(Visitor *);

      //private:
        Identifier *_name;
        std::list<VariableDeclaration *> *_vars;
        std::list<MethodDeclaration *> *_methods;
    };
  }
}

#endif
