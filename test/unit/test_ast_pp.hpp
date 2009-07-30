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

    void test_addition_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      AdditionExpression a(&i1, &i2);
      _pp.visit(&a);
      TS_ASSERT_EQUALS(_out.str(), "+\n\t1\n\t2\n");
    }

    void test_assignment_statement()
    {
      Identifier id("foo");
      IntegerLiteral il(1);
      AssignmentStatement a(&id, &il);
      _pp.visit(&a);
      TS_ASSERT_EQUALS(_out.str(), "=\n\tfoo\n\t1\n");
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

    void test_boolean_literal_true()
    {
      BooleanLiteral b(true);
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "true\n");
    }

    void test_boolean_literal_false()
    {
      BooleanLiteral b(false);
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "false\n");
    }

    void test_boolean_type()
    {
      BooleanType b;
      _pp.visit(&b);
      TS_ASSERT_EQUALS(_out.str(), "Boolean\n");
    }

    void test_call_expression()
    {
      ThisExpression t;
      Identifier i("do_foo");
      ExpressionList es;
      CallExpression c(&t, &i, &es);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "call\n\tthis\n\tdo_foo\n\texpression_list\n");
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

    // TODO: test_class_declaration_list

    void test_conjunction_expression()
    {
      BooleanLiteral b1(true);
      BooleanLiteral b2(false);
      ConjunctionExpression c(&b1, &b2);
      _pp.visit(&c);
      TS_ASSERT_EQUALS(_out.str(), "&&\n\ttrue\n\tfalse\n");
    }

    // TODO: test_expression_list

    void test_identifier()
    {
      Identifier i("foo");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "foo\n");
    }

    void test_identifier_expression()
    {
      IdentifierExpression i("foo");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "foo\n");
    }

    void test_identifier_type()
    {
      IdentifierType i("FooClass");
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "FooClass\n");
    }

    void test_if_then_else_statement()
    {
      BooleanLiteral b(true);
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      PrintStatement p1(&i1);
      PrintStatement p2(&i2);
      IfThenElseStatement if1(&b, &p1, &p2);
      _pp.visit(&if1);
      TS_ASSERT_EQUALS(_out.str(), "if\n\ttrue\n\tprint\n\t\t1\n\tprint\n\t\t2\n");
    }

    void test_integer_literal()
    {
      IntegerLiteral i(1);
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "1\n");
    }

    void test_integer_type()
    {
      IntegerType i;
      _pp.visit(&i);
      TS_ASSERT_EQUALS(_out.str(), "Integer\n");
    }

    void test_less_than_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      LessThanExpression l(&i1, &i2);
      _pp.visit(&l);
      TS_ASSERT_EQUALS(_out.str(), "<\n\t1\n\t2\n");
    }

    void test_main_class_declaration()
    {
      IntegerLiteral i(1);
      PrintStatement p(&i);
      MainClassDeclaration m(&p);
      _pp.visit(&m);
      TS_ASSERT_EQUALS(_out.str(), "main\n\tprint\n\t\t1\n");
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

    // TODO: test_method_declaration_list

    void test_multiplication_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      MultiplicationExpression m(&i1, &i2);
      _pp.visit(&m);
      TS_ASSERT_EQUALS(_out.str(), "*\n\t1\n\t2\n");
    }

    void test_negation_expression()
    {
      BooleanLiteral b(true);
      NegationExpression n(&b);
      _pp.visit(&n);
      TS_ASSERT_EQUALS(_out.str(), "!\n\ttrue\n");
    }

    void test_new_object_expression()
    {
      Identifier i("FooClass"); // TODO: Shouldn't we use IdentifierType here?
      NewObjectExpression n(&i);
      _pp.visit(&n);
      TS_ASSERT_EQUALS(_out.str(), "new\n\tFooClass\n");
    }

    void test_parameter_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      ParameterDeclaration p(&it, &id);
      _pp.visit(&p);
      TS_ASSERT_EQUALS(_out.str(), "parameter\n\tInteger\n\tfoo\n");
    }

    // TODO: test_parameter_declaration_list

    void test_print_statement()
    {
      IntegerLiteral i(1);
      PrintStatement p(&i);
      _pp.visit(&p);
      TS_ASSERT_EQUALS(_out.str(), "print\n\t1\n");
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

    // TODO: test_statement_list

    void test_subtraction_expression()
    {
      IntegerLiteral i1(1);
      IntegerLiteral i2(2);
      SubtractionExpression s(&i1, &i2);
      _pp.visit(&s);
      TS_ASSERT_EQUALS(_out.str(), "-\n\t1\n\t2\n");
    }

    void test_this_expression()
    {
      ThisExpression t;
      _pp.visit(&t);
      TS_ASSERT_EQUALS(_out.str(), "this\n");
    }

    void test_variable_declaration()
    {
      IntegerType it;
      Identifier id("foo");
      VariableDeclaration v(&it, &id);
      _pp.visit(&v);
      TS_ASSERT_EQUALS(_out.str(), "variable\n\tInteger\n\tfoo\n");
    }

    // TODO: test_variable_declaration_list

    void test_while_do_statement()
    {
      BooleanLiteral b(true);
      IntegerLiteral i(1);
      PrintStatement p(&i);
      WhileDoStatement w(&b, &p);
      _pp.visit(&w);
      TS_ASSERT_EQUALS(_out.str(), "while\n\ttrue\n\tprint\n\t\t1\n");
    }

    // This case was used to determine that a bug related to statement lists
    // was in the parser.
    void test_crashing_assignment_statement()
    {
      // main class
      IntegerLiteral main_class_int(1);
      PrintStatement main_class_print(&main_class_int);
      MainClassDeclaration main_class(&main_class_print);

      // class id and variables
      Identifier class_name("A");
      VariableDeclarationList class_vars;

      // method return type, name and params
      IntegerType method_return_type;
      Identifier method_name("a");
      ParameterDeclarationList method_params;

      // method vars
      IntegerType var_type;
      Identifier var_id("i");
      VariableDeclaration var(&var_type, &var_id);
      VariableDeclarationList method_vars;
      method_vars._list.push_back(&var);

      // method statements
      Identifier assigment_id("i");
      IntegerLiteral assigment_int(0);
      AssignmentStatement assigment(&assigment_id, &assigment_int);
      StatementList method_statements;
      method_statements._list.push_back(&assigment);

      // method return expression
      IntegerLiteral method_return_expr(0);

      // method
      MethodDeclaration class_method(&method_return_type,
                                     &method_name,
                                     &method_params,
                                     &method_vars,
                                     &method_statements,
                                     &method_return_expr);

      // class methods
      MethodDeclarationList class_methods;
      class_methods._list.push_back(&class_method);

      // class
      ClassDeclaration class_decl(&class_name, &class_vars, &class_methods);

      // classes
      ClassDeclarationList class_decls;
      class_decls._list.push_back(&class_decl);

      // program
      ProgramDeclaration program(&main_class, &class_decls);

      _pp.visit(&program);

      TS_ASSERT_EQUALS(_out.str(), "program\n\tmain\n\t\tprint\n\t\t\t1\n\tclass_declaration_list\n\t\tclass\n\t\t\tA\n\t\t\tvariable_declaration_list\n\t\t\tmethod_declaration_list\n\t\t\t\tmethod\n\t\t\t\t\tInteger\n\t\t\t\t\ta\n\t\t\t\t\tparameter_declaration_list\n\t\t\t\t\tvariable_declaration_list\n\t\t\t\t\t\tvariable\n\t\t\t\t\t\t\tInteger\n\t\t\t\t\t\t\ti\n\t\t\t\t\tstatement_list\n\t\t\t\t\t\t=\n\t\t\t\t\t\t\ti\n\t\t\t\t\t\t\t0\n\t\t\t\t\t0\n");
    }
};
