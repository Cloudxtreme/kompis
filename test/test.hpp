#include <cxxtest/TestSuite.h>
#include "ast/ast.hpp"

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

    void test_plus1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Plus p(i1, i2);
      _pp.visit(p);
      TS_ASSERT_EQUALS(_out.str(), "(+ 1 2)");
    }

    void test_plus2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(i2, i3);
      Plus p2(i1, p1);
      _pp.visit(p2);
      TS_ASSERT_EQUALS(_out.str(), "(+ 1 (+ 2 3))");
    }

    void test_plus3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(i1, i2);
      Plus p2(p1, i3);
      _pp.visit(p2);
      TS_ASSERT_EQUALS(_out.str(), "(+ (+ 1 2) 3)");
    }

    void test_minus1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Minus m(i1, i2);
      _pp.visit(m);
      TS_ASSERT_EQUALS(_out.str(), "(- 1 2)");
    }

    void test_minus2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Minus m1(i2, i3);
      Minus m2(i1, m1);
      _pp.visit(m2);
      TS_ASSERT_EQUALS(_out.str(), "(- 1 (- 2 3))");
    }

    void test_minus3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Minus m1(i1, i2);
      Minus m2(m1, i3);
      _pp.visit(m2);
      TS_ASSERT_EQUALS(_out.str(), "(- (- 1 2) 3)");
    }

    void test_times1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Times t(i1, i2);
      _pp.visit(t);
      TS_ASSERT_EQUALS(_out.str(), "(* 1 2)");
    }

    void test_times2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Times t1(i2, i3);
      Times t2(i1, t1);
      _pp.visit(t2);
      TS_ASSERT_EQUALS(_out.str(), "(* 1 (* 2 3))");
    }

    void test_times3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Times t1(i1, i2);
      Times t2(t1, i3);
      _pp.visit(t2);
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

    void test_and()
    {
      BooleanLiteral b1(true);
      BooleanLiteral b2(false);
      And a(b1, b2);
      _pp.visit(a);
      TS_ASSERT_EQUALS(_out.str(), "(and true false)");
    }

    void test_not()
    {
      BooleanLiteral b(true);
      Not n(b);
      _pp.visit(n);
      TS_ASSERT_EQUALS(_out.str(), "(not true)");
    }

    void test_less_than()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThan l(i1, i2);
      _pp.visit(l);
      TS_ASSERT_EQUALS(_out.str(), "(< 1 2)");
    }

    void test_identifier()
    {
      Identifier id("foo");
      _pp.visit(id);
      TS_ASSERT_EQUALS(_out.str(), "foo");
    }

    void test_plus_identifier()
    {
      Identifier id1("foo");
      Identifier id2("bar");
      Plus p(id1, id2);
      _pp.visit(p);
      TS_ASSERT_EQUALS(_out.str(), "(+ foo bar)");
    }

    void test_print_integer_literal()
    {
      IntegerLiteral i(1);
      Print p(i);
      _pp.visit(p);
      TS_ASSERT_EQUALS(_out.str(), "(print 1)");
    }

    void test_print_plus()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Plus pl(i1, i2);
      Print pr(pl);
      _pp.visit(pr);
      TS_ASSERT_EQUALS(_out.str(), "(print (+ 1 2))");
    }

    void test_if_then_else_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThan l(i1, i2);
      Print p1(i1);
      Print p2(i2);
      IfThenElseStatement i(l, p1, p2);
      _pp.visit(i);
      TS_ASSERT_EQUALS(_out.str(), "(if (< 1 2) (print 1) (print 2))");
    }

    void test_while_do_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThan l(i1, i2);
      Print p(i1);
      WhileDoStatement w(l, p);
      _pp.visit(w);
      TS_ASSERT_EQUALS(_out.str(), "(while (< 1 2) (print 1))");
    }

    void test_assignment_statement()
    {
      Identifier id("foo");
      IntegerLiteral i(1);
      AssignmentStatement a(id, i);
      _pp.visit(a);
      TS_ASSERT_EQUALS(_out.str(), "(= foo 1)");
    }
};
