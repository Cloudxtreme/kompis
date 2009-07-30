#!/bin/bash

# find all files matching test*.sh and run them
for TEST_FILE in $(ls test*.sh); do
  echo running $TEST_FILE...
  . $TEST_FILE
done
