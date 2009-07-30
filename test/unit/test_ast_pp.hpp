#include "cxxtest/TestSuite.h"
#include "ast/ast.hpp"
#include "ast/pretty_printer.hpp"

using namespace kompis;
using namespace ast;

class AbstractSyntaxTreePrettyPrinterTestSuite : public CxxTest::TestSuite
{
  private:
    PrettyPrinter _pp;
    std::ostringstream _out;

  public:
    AbstractSyntaxTreePrettyPrinterTestSuite() : _pp(_out), _out() {}

    static AbstractSyntaxTreePrettyPrinterTestSuite *createSuite()
    {
      return new AbstractSyntaxTreePrettyPrinterTestSuite();
    }

    static void destroySuite(AbstractSyntaxTreePrettyPrinterTestSuite *suite)
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
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "1\n");
    }

    void test_addition_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      AdditionExpression a(&i1, &i2);
      _pp.visit(&a);
      TS_ASSERT_EQUALS(_out.str(), "+\n\t1\n\t2\n");
    }

    void test_addition_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      AdditionExpression a1(&i2, &i3);
      AdditionExpression a2(&i1, &a1);
      _pp.visit(&a2);
      TS_ASSERT_EQUALS(_out.str(), "+\n\t1\n\t+\n\t\t2\n\t\t3\n");
    }

    void test_addition_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      AdditionExpression a1(&i1, &i2);
      AdditionExpression a2(&a1, &i3);
      _pp.visit(&a2);
      TS_ASSERT_EQUALS(_out.str(), "+\n\t+\n\t\t1\n\t\t2\n\t3\n");
    }

    void test_subtraction_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      SubtractionExpression s(&i1, &i2);
      _pp.visit(&s);
      TS_ASSERT_EQUALS(_out.str(), "-\n\t1\n\t2\n");
    }

    void test_subtraction_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      SubtractionExpression s1(&i2, &i3);
      SubtractionExpression s2(&i1, &s1);
      _pp.visit(&s2);
      TS_ASSERT_EQUALS(_out.str(), "-\n\t1\n\t-\n\t\t2\n\t\t3\n");
    }

    void test_subtraction_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      SubtractionExpression s1(&i1, &i2);
      SubtractionExpression s2(&s1, &i3);
      _pp.visit(&s2);
      TS_ASSERT_EQUALS(_out.str(), "-\n\t-\n\t\t1\n\t\t2\n\t3\n");
    }

    void test_multiplication_expression1()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      MultiplicationExpression m(&i1, &i2);
      _pp.visit(&m);
      TS_ASSERT_EQUALS(_out.str(), "*\n\t1\n\t2\n");
    }

    void test_multiplication_expression2()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      MultiplicationExpression m1(&i2, &i3);
      MultiplicationExpression m2(&i1, &m1);
      _pp.visit(&m2);
      TS_ASSERT_EQUALS(_out.str(), "*\n\t1\n\t*\n\t\t2\n\t\t3\n");
    }

    void test_multiplication_expression3()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      IntegerLiteral i3(3);
      MultiplicationExpression m1(&i1, &i2);
      MultiplicationExpression m2(&m1, &i3);
      _pp.visit(&m2);
      TS_ASSERT_EQUALS(_out.str(), "*\n\t*\n\t\t1\n\t\t2\n\t3\n");
    }

    void test_true_literal()
    {
      BooleanLiteral b(true);
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "true\n");
    }

    void test_false_literal()
    {
      BooleanLiteral b(false);
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "false\n");
    }

    void test_conjunction_expression()
    {
      BooleanLiteral b1(true);
      BooleanLiteral b2(false);
      ConjunctionExpression c(&b1, &b2);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "and\n\ttrue\n\tfalse\n");
    }

    void test_negation_expression()
    {
      BooleanLiteral b(true);
      NegationExpression n(&b);
      _pp.visit(&n);
      TS_ASSERT_EQUALS(_out.str(), "not\n\ttrue\n");
    }

    void test_less_than_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(&i1, &i2);
      _pp.visit(&l);
      TS_ASSERT_EQUALS(_out.str(), "<\n\t1\n\t2\n");
    }

    void test_identifier()
    {
      Identifier i("foo");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "foo\n");
    }

    void test_print_statement()
    {
      IntegerLiteral i(1);
      PrintStatement p(&i);
      _pp.visit(&p);
      TS_ASSERT_EQUALS(_out.str(), "print\n\t1\n");
    }

    void test_if_then_else_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(&i1, &i2);
      PrintStatement p1(&i1);
      PrintStatement p2(&i2);
      IfThenElseStatement if1(&l, &p1, &p2);
      _pp.visit(&if1);
      TS_ASSERT_EQUALS(_out.str(), "if\n\t<\n\t\t1\n\t\t2\n\tprint\n\t\t1\n\tprint\n\t\t2\n");
    }

    void test_while_do_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(&i1, &i2);
      PrintStatement p(&i1);
      WhileDoStatement w(&l, &p);
      _pp.visit(&w);
      TS_ASSERT_EQUALS(_out.str(), "while\n\t<\n\t\t1\n\t\t2\n\tprint\n\t\t1\n");
    }

    void test_assignment_statement()
    {
      Identifier id("foo");
      IntegerLiteral il(1);
      AssignmentStatement a(&id, &il);
      _pp.visit(&a);
      TS_ASSERT_EQUALS(_out.str(), "=\n\tfoo\n\t1\n");
    }

    void test_boolean_type()
    {
      BooleanType b;
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "Boolean\n");
    }

    void test_integer_type()
    {
      IntegerType i;
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "Integer\n");
    }

    void test_identifier_type()
    {
      IdentifierType i("FooClass");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "FooClass\n");
    }

    void test_variable_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      VariableDeclaration v(&it, &id);
      _pp.visit(&v);
      TS_ASSERT_EQUALS(_out.str(), "variable\n\tInteger\n\tfoo\n");
    }

    void test_parameter_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      ParameterDeclaration p(&it, &id);
      _pp.visit(&p);
      TS_ASSERT_EQUALS(_out.str(), "parameter\n\tInteger\n\tfoo\n");
    }

    void test_this_expression()
    {
      ThisExpression t;
      _pp.visit(&t);
      TS_ASSERT_EQUALS(_out.str(), "this\n");
    }

    void test_identifier_expression()
    {
      IdentifierExpression i("foo");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "foo\n");
    }

    void test_new_object_expression()
    {
      Identifier i("foo");
      NewObjectExpression n(&i);
      _pp.visit(&n);
      TS_ASSERT_EQUALS(_out.str(), "new\n\tfoo\n");
    }

    void test_call_expression_without_arguments()
    {
      ThisExpression t;
      Identifier i("do_foo");
      ExpressionList es;
      CallExpression c(&t, &i, &es);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "call\n\tthis\n\tdo_foo\n\texpression_list\n");
    }

    void test_call_expression_with_one_argument()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral il(1);
      ExpressionList es;
      es._list.push_back(&il);
      CallExpression c(&t, &id, &es);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "call\n\tthis\n\tdo_foo\n\texpression_list\n\t\t1\n");
    }

    void test_call_expression_with_two_arguments()
    {
      ThisExpression t;
      Identifier id("do_foo");
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      ExpressionList es;
      es._list.push_back(&i1);
      es._list.push_back(&i2);
      CallExpression c(&t, &id, &es);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "call\n\tthis\n\tdo_foo\n\texpression_list\n\t\t1\n\t\t2\n");
    }

    void test_block_statement()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      PrintStatement p1(&i1);
      PrintStatement p2(&i2);
      StatementList ss;
      ss._list.push_back(&p1);
      ss._list.push_back(&p2);
      BlockStatement b(&ss);
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "block\n\tstatement_list\n\t\tprint\n\t\t\t1\n\t\tprint\n\t\t\t2\n");
    }

    void test_method_declaration()
    {
      IntegerType it;
      Identifier id("do_foo");
      ParameterDeclarationList ps;
      VariableDeclarationList vs;
      StatementList ss;
      IntegerLiteral il(1);
      MethodDeclaration m(&it, &id, &ps, &vs, &ss, &il);
      _pp.visit(&m);
      TS_ASSERT_EQUALS(_out.str(), "method\n\tInteger\n\tdo_foo\n\tparameter_declaration_list\n\tvariable_declaration_list\n\tstatement_list\n\t1\n");
    }

    void test_class_declaration()
    {
      Identifier i("FooClass");
      VariableDeclarationList vs;
      MethodDeclarationList ms;
      ClassDeclaration c(&i, &vs, &ms);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "class\n\tFooClass\n\tvariable_declaration_list\n\tmethod_declaration_list\n");
    }

    void test_main_class_declaration()
    {
      IntegerLiteral il(1);
      PrintStatement p(&il);
      MainClassDeclaration m(&p);
      _pp.visit(&m);
      TS_ASSERT_EQUALS(_out.str(), "main\n\tprint\n\t\t1\n");
    }

    void test_program_declaration()
    {
      IntegerLiteral il(1);
      PrintStatement ps(&il);
      MainClassDeclaration m(&ps);
      ClassDeclarationList cs;
      ProgramDeclaration pd(&m, &cs);
      _pp.visit(&pd);
      TS_ASSERT_EQUALS(_out.str(), "program\n\tmain\n\t\tprint\n\t\t\t1\n\tclass_declaration_list\n");
    }

    // This case was used to determine that a bug related to statement lists
    // was in the parser.
    void test_crashing_assignment_statement()
    {
      // main class
      IntegerLiteral mcd_il(1);
      PrintStatement mcd_ps(&mcd_il);
      MainClassDeclaration mcd(&mcd_ps);

      // class id and variables
      Identifier c_id("A");
      VariableDeclarationList c_vs;

      // method return type, name and params
      IntegerType m_it;
      Identifier m_id("a");
      ParameterDeclarationList m_ps;

      // method vars
      IntegerType var_it;
      Identifier var_id("i");
      VariableDeclaration var(&var_it, &var_id);
      VariableDeclarationList m_vs;
      m_vs._list.push_back(&var);

      // method statements
      Identifier ass_id("i");
      IntegerLiteral ass_il(0);
      AssignmentStatement ass(&ass_id, &ass_il);
      StatementList m_ss;
      m_ss._list.push_back(&ass);

      // method return expression
      IntegerLiteral m_il(0);

      // method
      MethodDeclaration c_m(&m_it, &m_id, &m_ps, &m_vs, &m_ss, &m_il);

      // class methods
      MethodDeclarationList c_ms;
      c_ms._list.push_back(&c_m);

      // class
      ClassDeclaration c(&c_id, &c_vs, &c_ms);

      // classes
      ClassDeclarationList cs;
      cs._list.push_back(&c);

      // program
      ProgramDeclaration pd(&mcd, &cs);

      _pp.visit(&pd);

      TS_ASSERT_EQUALS(_out.str(), "program\n\tmain\n\t\tprint\n\t\t\t1\n\tclass_declaration_list\n\t\tclass\n\t\t\tA\n\t\t\tvariable_declaration_list\n\t\t\tmethod_declaration_list\n\t\t\t\tmethod\n\t\t\t\t\tInteger\n\t\t\t\t\ta\n\t\t\t\t\tparameter_declaration_list\n\t\t\t\t\tvariable_declaration_list\n\t\t\t\t\t\tvariable\n\t\t\t\t\t\t\tInteger\n\t\t\t\t\t\t\ti\n\t\t\t\t\tstatement_list\n\t\t\t\t\t\t=\n\t\t\t\t\t\t\ti\n\t\t\t\t\t\t\t0\n\t\t\t\t\t0\n");
    }
};
