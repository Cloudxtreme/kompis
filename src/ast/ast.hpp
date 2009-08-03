#ifndef KOMPIS_AST_AST_HPP
#define KOMPIS_AST_AST_HPP

#include "ast/addition_expression.hpp"
#include "ast/assignment_statement.hpp"
#include "ast/block_statement.hpp"
#include "ast/boolean_literal.hpp"
#include "ast/boolean_type.hpp"
#include "ast/call_expression.hpp"
#include "ast/class_declaration.hpp"
#include "ast/class_declaration_list.hpp"
#include "ast/conjunction_expression.hpp"
#include "ast/expression.hpp"
#include "ast/expression_list.hpp"
#include "ast/identifier.hpp"
#include "ast/identifier_expression.hpp"
#include "ast/identifier_type.hpp"
#include "ast/if_then_else_statement.hpp"
#include "ast/integer_literal.hpp"
#include "ast/integer_type.hpp"
#include "ast/less_than_expression.hpp"
#include "ast/list.hpp"
#include "ast/main_class_declaration.hpp"
#include "ast/method_declaration.hpp"
#include "ast/method_declaration_list.hpp"
#include "ast/multiplication_expression.hpp"
#include "ast/negation_expression.hpp"
#include "ast/new_object_expression.hpp"
#include "ast/node.hpp"
#include "ast/parameter_declaration.hpp"
#include "ast/parameter_declaration_list.hpp"
#include "ast/print_statement.hpp"
#include "ast/program_declaration.hpp"
#include "ast/statement.hpp"
#include "ast/statement_list.hpp"
#include "ast/subtraction_expression.hpp"
#include "ast/this_expression.hpp"
#include "ast/type.hpp"
#include "ast/variable_declaration.hpp"
#include "ast/variable_declaration_list.hpp"
#include "ast/visitor.hpp"
#include "ast/while_do_statement.hpp"

#endif
