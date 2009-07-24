%{
#include <stdio.h>

void yyerror(const char *str);
int yywrap();

int yydebug = 1;
%}

%token BOOLEAN CLASS ELSE FALSE IDENTIFIER IF INT INTEGER_LITERAL MAIN NEW PRINT PUBLIC RETURN STATIC STRING THIS TRUE VOID WHILE
%left ','
%right '='
%left AND
%left '<'
%left '+' '-'
%left '*'
%right '!'
%left '.'

%%

program
  : main_class class_declarations
  ;

main_class
  : CLASS IDENTIFIER '{' PUBLIC STATIC VOID MAIN '(' STRING '[' ']' IDENTIFIER ')' '{' statement '}' '}'
  ;

class_declarations
  :
  | class_declarations class_declaration
  ;

class_declaration
  : CLASS IDENTIFIER '{' variable_declarations method_declarations '}'
  ;

variable_declarations
  :
  | variable_declarations variable_declaration
  ;

variable_declaration
  : type IDENTIFIER ';'
  ;

method_declarations
  :
  | method_declarations method_declaration
  ;

method_declaration
  : PUBLIC type IDENTIFIER '(' parameter_list ')' '{' variable_declarations statements RETURN expression ';' '}'
  ;

parameter_list
  :
  | type IDENTIFIER parameter_rests
  ;

parameter_rests
  :
  | parameter_rests parameter_rest
  ;

parameter_rest
  : ',' type IDENTIFIER
  ;

type
  : BOOLEAN
  | INT
  | IDENTIFIER
  ;

statements
  :
  | statement statements // right recursive, to fix a shift/reduce conflict in method bodies
  ;

statement
  : '{' statements '}'
  | IF '(' expression ')' statement ELSE statement
  | WHILE '(' expression ')' statement
  | PRINT '(' expression ')' ';'
  | IDENTIFIER '=' expression ';'
  ;

expression_list
  :
  | expression expression_rests
  ;

expression_rests
  :
  | expression_rest expression_rests
  ;

expression_rest
  : ',' type IDENTIFIER
  ;

expression
  : expression '+' expression
  | expression '-' expression
  | expression '*' expression
  | expression '<' expression
  | expression AND expression
  | expression '.' IDENTIFIER '(' expression_list ')'
  | INTEGER_LITERAL
  | TRUE
  | FALSE
  | IDENTIFIER
  | THIS
  | NEW IDENTIFIER '(' ')'
  | '!' expression
  | '(' expression ')'
  ;

%%

extern int line_num;

void yyerror(const char *str)
{
  fprintf(stderr, "error on line %d: %s\n", line_num, str);
}

int yywrap()
{
  return 1;
}

int main(int argc, char *argv[])
{
  yyparse();
  return 0;
}
