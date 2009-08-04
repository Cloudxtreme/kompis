#!/bin/bash

pushd $(dirname $0)

# find all files matching test*.java, run them through compiler, compare output with expected
for INPUT_FILE in $(ls test*.java); do
  echo testing $INPUT_FILE...

  # set some filenames
  AST_FILE=${INPUT_FILE/.java/.ast}
  ERR_FILE=${INPUT_FILE/.java/.err}
  [ -f $AST_FILE ] && ASTOUT_FILE=${INPUT_FILE/.java/.astout} || ASTOUT_FILE="/dev/null"
  [ -f $ERR_FILE ] && ERROUT_FILE=${INPUT_FILE/.java/.errout} || ERROUT_FILE="/dev/null"

  # run kompis
  ../../bin/kompis <$INPUT_FILE >$ASTOUT_FILE 2>$ERROUT_FILE

  # if a *.ast file with expected stdout output exists, diff it with *.astout
  # remove output file only if there was no diff
  [ -f $AST_FILE ] && diff -q $AST_FILE $ASTOUT_FILE && rm $ASTOUT_FILE

  # if a *.err file with expected stderr output exists, diff it with *.errout
  # remove output file only if there was no diff
  [ -f $ERR_FILE ] && diff -q $ERR_FILE $ERROUT_FILE && rm $ERROUT_FILE
done

popd
