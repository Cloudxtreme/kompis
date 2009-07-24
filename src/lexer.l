%{
#include <stdlib.h>
#include "parser.tab.hpp"

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
"main"                  { return MAIN; }
"new"                   { return NEW; }
"public"                { return PUBLIC; }
"return"                { return RETURN; }
"static"                { return STATIC; }
"this"                  { return THIS; }
"true"                  { return TRUE; }
"void"                  { return VOID; }
"while"                 { return WHILE; }

[A-Za-z_][A-Za-z0-9_]*  { return IDENTIFIER; }

[0-9]+                  { return INTEGER_LITERAL; }

[-+*<!=.,;(){}\[\]]     { return yytext[0]; }
"&&"                    { return AND; }

[ \t]+                  // ignore whitespace
\n                      { ++line_num; }
.                       { yyerror("unknown token"); }

%%
