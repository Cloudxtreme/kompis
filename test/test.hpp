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
      pp.visit(&i1);
      TS_ASSERT_EQUALS(out.str(), "1");
    }

    void test_plus1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Plus p1(&i1, &i2);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(&p1);
      TS_ASSERT_EQUALS(out.str(), "(+ 1 2)");
    }

    void test_plus2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(&i2, &i3);
      Plus p2(&i1, &p1);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(&p2);
      TS_ASSERT_EQUALS(out.str(), "(+ 1 (+ 2 3))");
    }

    void test_plus3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      Plus p1(&i1, &i2);
      Plus p2(&p1, &i3);
      std::ostringstream out;
      PrettyPrinter pp(out);
      pp.visit(&p2);
      TS_ASSERT_EQUALS(out.str(), "(+ (+ 1 2) 3)");
    }
};
