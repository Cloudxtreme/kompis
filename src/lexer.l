%{
// we need to include this before the parser header...
// yup, it's ugly
#include "ast/ast.hpp"
using namespace kompis;
using namespace ast;

#include "parser.hpp"

int line_num = 1;
%}

%x COMMENT LINECOMMENT

%%

"/*"                    BEGIN COMMENT;
<COMMENT>"*/"           BEGIN INITIAL;
<COMMENT>\n             { ++line_num; }
<COMMENT>.              // ignore everything else

"//"                    BEGIN LINECOMMENT;
<LINECOMMENT>./\n       BEGIN INITIAL;
<LINECOMMENT>.          // ignore everything else

"String"                { return STRING; }
"System.out.println"    { return PRINT; }
"boolean"               { return BOOLEAN; }
"class"                 { return CLASS; }
"else"                  { return ELSE; }
"false"                 { return FALSE; }
"if"                    { return IF; }
"int"                   { return INT; }
"length"                { return LENGTH; }
"main"                  { return MAIN; }
"new"                   { return NEW; }
"public"                { return PUBLIC; }
"return"                { return RETURN; }
"static"                { return STATIC; }
"this"                  { return THIS; }
"true"                  { return TRUE; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

[A-Za-z_][A-Za-z0-9_]*  { yylval.text = strdup(yytext); return IDENTIFIER; /* TODO: memory leak */ }

[0-9]+                  { yylval.value = strtol(yytext, NULL, 10); return INT_LITERAL; }

[-+*<!=.,;(){}\[\]]     { return yytext[0]; }
"&&"                    { return AND; }

[ \t]+                  // ignore whitespace
\n                      { ++line_num; }
.                       { /*yyerror("unknown token");*/ }

%%
