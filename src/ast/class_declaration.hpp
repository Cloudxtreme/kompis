#ifndef KOMPIS_AST_CLASS_DECLARATION_HPP
#define KOMPIS_AST_CLASS_DECLARATION_HPP

#include "ast/node.hpp"

namespace kompis
{
  namespace ast
  {
    class Identifier;
    class MethodDeclarationList;
    class VariableDeclarationList;
    class Visitor;
    class VisitorData;

    class ClassDeclaration : public Node
    {
      public:
        ClassDeclaration(Identifier *name,
                         VariableDeclarationList *vars,
                         MethodDeclarationList *methods)
          : _name(name),
            _vars(vars),
            _methods(methods) {}

        VisitorData *accept(Visitor *);

      //private:
        Identifier *_name;
        VariableDeclarationList *_vars;
        MethodDeclarationList *_methods;
    };
  }
}

#endif
