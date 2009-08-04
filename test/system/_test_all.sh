#!/bin/bash

pushd $(dirname $0)

# build compiler
pushd ../../src
flex lexer.l && bison -d parser.ypp && g++ -Wall -I. -o kompis lex.yy.c parser.tab.cpp ast/*.cpp sema/*.cpp
popd

# find all files matching test*.java, run them through compiler, compare output with expected
for INPUT_FILE in $(ls test*.java); do
  echo testing $INPUT_FILE...

  # run kompis, put stdout in *.astout and stderr in *.errout
  ../../src/kompis <$INPUT_FILE >${INPUT_FILE/.java/.astout} 2>${INPUT_FILE/.java/.errout}

  # if a *.ast file with expected stdout output exists, diff it with *.astout
  if [ -f ${INPUT_FILE/.java/.ast} ]; then
    diff -u ${INPUT_FILE/.java/.ast} ${INPUT_FILE/.java/.astout}
  fi

  # if a *.err file with expected stderr output exists, diff it with *.errout
  if [ -f ${INPUT_FILE/.java/.err} ]; then
    diff -u ${INPUT_FILE/.java/.err} ${INPUT_FILE/.java/.errout}
  fi

  # remove output files
  rm ${INPUT_FILE/.java/.astout} ${INPUT_FILE/.java/.errout}
done

# remove build products
pushd ../../src
rm -f kompis lex.yy.c parser.tab.cpp parser.tab.hpp
popd

popd
