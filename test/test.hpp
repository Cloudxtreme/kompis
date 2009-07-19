#include <cxxtest/TestSuite.h>
#include "ast/ast.hpp"

using namespace kompis;
using namespace ast;

class PrettyPrinterTestSuite : public CxxTest::TestSuite
{
  public:
    void test_integer_literal()
    {
      IntegerLiteral i1(1);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(i1);
      TS_ASSERT_EQUALS(out.str(), "1");
    }

    void test_plus1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Plus p1(i1, i2);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(p1);
      TS_ASSERT_EQUALS(out.str(), "(+ 1 2)");
    }

    void test_plus2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(i2, i3);
      Plus p2(i1, p1);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(p2);
      TS_ASSERT_EQUALS(out.str(), "(+ 1 (+ 2 3))");
    }

    void test_plus3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(i1, i2);
      Plus p2(p1, i3);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(p2);
      TS_ASSERT_EQUALS(out.str(), "(+ (+ 1 2) 3)");
    }

    void test_minus1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Minus m1(i1, i2);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(m1);
      TS_ASSERT_EQUALS(out.str(), "(- 1 2)");
    }

    void test_minus2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Minus m1(i2, i3);
      Minus m2(i1, m1);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(m2);
      TS_ASSERT_EQUALS(out.str(), "(- 1 (- 2 3))");
    }

    void test_minus3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Minus m1(i1, i2);
      Minus m2(m1, i3);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(m2);
      TS_ASSERT_EQUALS(out.str(), "(- (- 1 2) 3)");
    }

    void test_times1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Times t1(i1, i2);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(t1);
      TS_ASSERT_EQUALS(out.str(), "(* 1 2)");
    }

    void test_times2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Times t1(i2, i3);
      Times t2(i1, t1);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(t2);
      TS_ASSERT_EQUALS(out.str(), "(* 1 (* 2 3))");
    }

    void test_times3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Times t1(i1, i2);
      Times t2(t1, i3);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(t2);
      TS_ASSERT_EQUALS(out.str(), "(* (* 1 2) 3)");
    }

    void test_true_literal()
    {
      TrueLiteral t;
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(t);
      TS_ASSERT_EQUALS(out.str(), "true");
    }

    void test_false_literal()
    {
      FalseLiteral f;
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(f);
      TS_ASSERT_EQUALS(out.str(), "false");
    }

    void test_and1()
    {
      TrueLiteral t;
      FalseLiteral f;
      And a(t, f);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(a);
      TS_ASSERT_EQUALS(out.str(), "(and true false)");
    }

    void test_not1()
    {
      TrueLiteral t;
      Not n(t);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(n);
      TS_ASSERT_EQUALS(out.str(), "(not true)");
    }

    void test_less_than1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThan l(i1, i2);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(l);
      TS_ASSERT_EQUALS(out.str(), "(< 1 2)");
    }
};
