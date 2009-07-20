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

    void test_plus_identifier_expression()
    {
      IdentifierExpression id1("foo");
      IdentifierExpression id2("bar");
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
      IdentifierType id("FooClass");
      _pp.visit(id);
      TS_ASSERT_EQUALS(_out.str(), "FooClass");
    }

    void test_variable_declaration()
    {
      IntegerType i;
      Identifier id("foo");
      VariableDeclaration v(i, id);
      _pp.visit(v);
      TS_ASSERT_EQUALS(_out.str(), "(variable Integer foo)");
    }

    void test_parameter_declaration()
    {
      IntegerType i;
      Identifier id("foo");
      ParameterDeclaration p(i, id);
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
      IdentifierExpression id("foo");
      _pp.visit(id);
      TS_ASSERT_EQUALS(_out.str(), "foo");
    }

    void test_new_object_expression()
    {
      Identifier id("foo");
      NewObjectExpression n(id);
      _pp.visit(n);
      TS_ASSERT_EQUALS(_out.str(), "(new foo)");
    }

    void test_call_expression0()
    {
      ThisExpression t;
      Identifier id("do_foo");
      std::list<Expression *> args;
      CallExpression c(t, id, args);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list))");
    }

    void test_call_expression1()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral i(1);
      std::list<Expression *> args;
      args.push_back(&i);
      CallExpression c(t, id, args);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list 1))");
    }

    void test_call_expression2()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      std::list<Expression *> args;
      args.push_back(&i1);
      args.push_back(&i2);
      CallExpression c(t, id, args);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(call this do_foo (list 1 2))");
    }

    void test_block_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      Print p1(i1);
      Print p2(i2);
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
      Identifier id("FooClass");
      std::list<VariableDeclaration *> vs;
      std::list<MethodDeclaration *> ms;
      ClassDeclaration c(id, vs, ms);
      _pp.visit(c);
      TS_ASSERT_EQUALS(_out.str(), "(class FooClass (list) (list))");
    }

    void test_main_class_declaration()
    {
      Identifier id("MainClass");
      IntegerLiteral i(1);
      Print p(i);
      MainClassDeclaration m(id, p);
      _pp.visit(m);
      TS_ASSERT_EQUALS(_out.str(), "(main MainClass (print 1))");
    }

    void test_program_declaration()
    {
      Identifier id1("MainClass");
      IntegerLiteral i(1);
      Print p(i);
      MainClassDeclaration m(id1, p);
      std::list<ClassDeclaration *> cs;
      ProgramDeclaration pd(m, cs);
      _pp.visit(pd);
      TS_ASSERT_EQUALS(_out.str(), "(program (main MainClass (print 1)) (list))");
    }
};
