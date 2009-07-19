#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

namespace kompis
{
  namespace ast
  {
    class IntegerLiteral;
    class Minus;
    class Plus;
    class Times;

    class Visitor
    {
      public:
        virtual ~Visitor() {}
        virtual void visit(IntegerLiteral &) = 0;
        virtual void visit(Minus &) = 0;
        virtual void visit(Plus &) = 0;
        virtual void visit(Times &) = 0;
    };
  }
}

#endif
