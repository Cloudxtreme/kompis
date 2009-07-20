#include <cxxtest/TestSuite.h>
#include "ast/ast.hpp"
#include "ast/pretty_printer.hpp"

using namespace kompis;
using namespace ast;

class PrettyPrinterTestSuite : public CxxTest::TestSuite
{
  private:
    PrettyPrinter _pp;
    std::ostringstream _out;

  public:
    PrettyPrinterTestSuite() : _pp(_out), _out() {}

    static PrettyPrinterTestSuite *createSuite()
    {
      return new PrettyPrinterTestSuite();
    }

    static void destroySuite(PrettyPrinterTestSuite *suite)
    {
      delete suite;
    }

    void setUp()
    {
      _out.str("");
    }

    void tearDown()
    {
    }

    void test_integer_literal()
    {
      IntegerLiteral i(1);
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "1");
    }

    void test_addition_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      AdditionExpression a(i1, i2);
      _pp.visit(a);
      TS_ASSERT_EQUALS(_out.str(), "(+ 1 2)");
    }

    void test_addition_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      AdditionExpression a1(i2, i3);
      AdditionExpression a2(i1, a1);
      _pp.visit(a2);
      TS_ASSERT_EQUALS(_out.str(), "(+ 1 (+ 2 3))");
    }

    void test_addition_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      AdditionExpression a1(i1, i2);
      AdditionExpression a2(a1, i3);
      _pp.visit(a2);
      TS_ASSERT_EQUALS(_out.str(), "(+ (+ 1 2) 3)");
    }

    void test_subtraction_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      SubtractionExpression s(i1, i2);
      _pp.visit(s);
      TS_ASSERT_EQUALS(_out.str(), "(- 1 2)");
    }

    void test_subtraction_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      SubtractionExpression s1(i2, i3);
      SubtractionExpression s2(i1, s1);
      _pp.visit(s2);
      TS_ASSERT_EQUALS(_out.str(), "(- 1 (- 2 3))");
    }

    void test_subtraction_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      SubtractionExpression s1(i1, i2);
      SubtractionExpression s2(s1, i3);
      _pp.visit(s2);
      TS_ASSERT_EQUALS(_out.str(), "(- (- 1 2) 3)");
    }

    void test_multiplication_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      MultiplicationExpression m(i1, i2);
      _pp.visit(m);
      TS_ASSERT_EQUALS(_out.str(), "(* 1 2)");
    }

    void test_multiplication_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      MultiplicationExpression m1(i2, i3);
      MultiplicationExpression m2(i1, m1);
      _pp.visit(m2);
      TS_ASSERT_EQUALS(_out.str(), "(* 1 (* 2 3))");
    }

    void test_multiplication_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      MultiplicationExpression m1(i1, i2);
      MultiplicationExpression m2(m1, i3);
      _pp.visit(m2);
      TS_ASSERT_EQUALS(_out.str(), "(* (* 1 2) 3)");
    }

    void test_true_literal()
    {
      BooleanLiteral b(true);
      _pp.visit(b);
      TS_ASSERT_EQUALS(_out.str(), "true");
    }

    void test_false_literal()
    {
      BooleanLiteral b(false);
      _pp.visit(b);
      TS_ASSERT_EQUALS(_out.str(), "false");
    }

    void test_conjunction_expression()
    {
      BooleanLiteral b1(true);
      BooleanLiteral b2(false);
      ConjunctionExpression c(b1, b2);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(and true false)");
    }

    void test_negation_expression()
    {
      BooleanLiteral b(true);
      NegationExpression n(b);
      _pp.visit(n);
      TS_ASSERT_EQUALS(_out.str(), "(not true)");
    }

    void test_less_than_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(i1, i2);
      _pp.visit(l);
      TS_ASSERT_EQUALS(_out.str(), "(< 1 2)");
    }

    void test_identifier()
    {
      Identifier i("foo");
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "foo");
    }

    void test_print_statement()
    {
      IntegerLiteral i(1);
      PrintStatement p(i);
      _pp.visit(p);
      TS_ASSERT_EQUALS(_out.str(), "(print 1)");
    }

    void test_if_then_else_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(i1, i2);
      PrintStatement p1(i1);
      PrintStatement p2(i2);
      IfThenElseStatement if1(l, p1, p2);
      _pp.visit(if1);
      TS_ASSERT_EQUALS(_out.str(), "(if (< 1 2) (print 1) (print 2))");
    }

    void test_while_do_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(i1, i2);
      PrintStatement p(i1);
      WhileDoStatement w(l, p);
      _pp.visit(w);
      TS_ASSERT_EQUALS(_out.str(), "(while (< 1 2) (print 1))");
    }

    void test_assignment_statement()
    {
      Identifier id("foo");
      IntegerLiteral il(1);
      AssignmentStatement a(id, il);
      _pp.visit(a);
      TS_ASSERT_EQUALS(_out.str(), "(= foo 1)");
    }

    void test_boolean_type()
    {
      BooleanType b;
      _pp.visit(b);
      TS_ASSERT_EQUALS(_out.str(), "Boolean");
    }

    void test_integer_type()
    {
      IntegerType i;
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "Integer");
    }

    void test_identifier_type()
    {
      IdentifierType i("FooClass");
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "FooClass");
    }

    void test_variable_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      VariableDeclaration v(it, id);
      _pp.visit(v);
      TS_ASSERT_EQUALS(_out.str(), "(variable Integer foo)");
    }

    void test_parameter_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      ParameterDeclaration p(it, id);
      _pp.visit(p);
      TS_ASSERT_EQUALS(_out.str(), "(parameter Integer foo)");
    }

    void test_this_expression()
    {
      ThisExpression t;
      _pp.visit(t);
      TS_ASSERT_EQUALS(_out.str(), "this");
    }

    void test_identifier_expression()
    {
      IdentifierExpression i("foo");
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "foo");
    }

    void test_new_object_expression()
    {
      Identifier i("foo");
      NewObjectExpression n(i);
      _pp.visit(n);
      TS_ASSERT_EQUALS(_out.str(), "(new foo)");
    }

    void test_call_expression_without_arguments()
    {
      ThisExpression t;
      Identifier i("do_foo");
      std::list<Expression *> es;
      CallExpression c(t, i, es);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list))");
    }

    void test_call_expression_with_one_argument()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral il(1);
      std::list<Expression *> es;
      es.push_back(&il);
      CallExpression c(t, id, es);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list 1))");
    }

    void test_call_expression_with_two_arguments()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      std::list<Expression *> es;
      es.push_back(&i1);
      es.push_back(&i2);
      CallExpression c(t, id, es);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list 1 2))");
    }

    void test_block_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      PrintStatement p1(i1);
      PrintStatement p2(i2);
      std::list<Statement *> ss;
      ss.push_back(&p1);
      ss.push_back(&p2);
      BlockStatement b(ss);
      _pp.visit(b);
      TS_ASSERT_EQUALS(_out.str(), "(block (list (print 1) (print 2)))");
    }

    void test_method_declaration()
    {
      IntegerType it;
      Identifier id("do_foo");
      std::list<ParameterDeclaration *> ps;
      std::list<VariableDeclaration *> vs;
      std::list<Statement *> ss;
      IntegerLiteral il(1);
      MethodDeclaration m(it, id, ps, vs, ss, il);
      _pp.visit(m);
      TS_ASSERT_EQUALS(_out.str(), "(method Integer do_foo (list) (list) (list) 1)");
    }

    void test_class_declaration()
    {
      Identifier i("FooClass");
      std::list<VariableDeclaration *> vs;
      std::list<MethodDeclaration *> ms;
      ClassDeclaration c(i, vs, ms);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(class FooClass (list) (list))");
    }

    void test_main_class_declaration()
    {
      Identifier id("MainClass");
      IntegerLiteral il(1);
      PrintStatement p(il);
      MainClassDeclaration m(id, p);
      _pp.visit(m);
      TS_ASSERT_EQUALS(_out.str(), "(main MainClass (print 1))");
    }

    void test_program_declaration()
    {
      Identifier id("MainClass");
      IntegerLiteral il(1);
      PrintStatement ps(il);
      MainClassDeclaration m(id, ps);
      std::list<ClassDeclaration *> cs;
      ProgramDeclaration pd(m, cs);
      _pp.visit(pd);
      TS_ASSERT_EQUALS(_out.str(), "(program (main MainClass (print 1)) (list))");
    }
};
