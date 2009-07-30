#!/bin/bash

# build compiler
pushd ../../src
flex lexer.l && bison -d parser.ypp && g++ -Wall -I. -o kompis lex.yy.c parser.tab.cpp ast/*.cpp
popd

for INPUT_FILE in $(ls test*.java); do
  ../../src/kompis <$INPUT_FILE >${INPUT_FILE/.java/.out}
  diff -u ${INPUT_FILE/.java/.ast} ${INPUT_FILE/.java/.out}
  rm ${INPUT_FILE/.java/.out}
done

# remove build products
pushd ../../src
rm -f kompis lex.yy.c parser.tab.cpp parser.tab.hpp
popd
