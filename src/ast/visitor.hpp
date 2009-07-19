#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

namespace kompis
{
  namespace ast
  {
    class And;
    class FalseLiteral;
    class IntegerLiteral;
    class LessThan;
    class Minus;
    class Plus;
    class Times;
    class TrueLiteral;

    class Visitor
    {
      public:
        virtual ~Visitor() {}
        virtual void visit(And &) = 0;
        virtual void visit(FalseLiteral &) = 0;
        virtual void visit(IntegerLiteral &) = 0;
        virtual void visit(LessThan &) = 0;
        virtual void visit(Minus &) = 0;
        virtual void visit(Plus &) = 0;
        virtual void visit(Times &) = 0;
        virtual void visit(TrueLiteral &) = 0;
    };
  }
}

#endif
