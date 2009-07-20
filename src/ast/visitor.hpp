#ifndef KOMPIS_AST_VISITOR_HPP
#define KOMPIS_AST_VISITOR_HPP

namespace kompis
{
  namespace ast
  {
    class And;
    class AssignmentStatement;
    class BooleanLiteral;
    class BooleanType;
    class Identifier;
    class IdentifierType;
    class IfThenElseStatement;
    class IntegerLiteral;
    class IntegerType;
    class LessThan;
    class Minus;
    class Not;
    class Plus;
    class ParameterDeclaration;
    class Print;
    class ThisExpression;
    class Times;
    class VariableDeclaration;
    class WhileDoStatement;

    class Visitor
    {
      public:
        virtual ~Visitor() {}
        virtual void visit(And &) = 0;
        virtual void visit(AssignmentStatement &) = 0;
        virtual void visit(BooleanLiteral &) = 0;
        virtual void visit(BooleanType &) = 0;
        virtual void visit(Identifier &) = 0;
        virtual void visit(IdentifierType &) = 0;
        virtual void visit(IfThenElseStatement &) = 0;
        virtual void visit(IntegerLiteral &) = 0;
        virtual void visit(IntegerType &) = 0;
        virtual void visit(LessThan &) = 0;
        virtual void visit(Minus &) = 0;
        virtual void visit(Not &) = 0;
        virtual void visit(Plus &) = 0;
        virtual void visit(ParameterDeclaration &) = 0;
        virtual void visit(Print &) = 0;
        virtual void visit(ThisExpression &) = 0;
        virtual void visit(Times &) = 0;
        virtual void visit(VariableDeclaration &) = 0;
        virtual void visit(WhileDoStatement &) = 0;
    };
  }
}

#endif
