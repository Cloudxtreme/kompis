#!/bin/sh
../cxxtest/cxxtestgen.pl --error-printer -o test.cpp test.hpp && g++ -Wall -I../cxxtest -I../../src -o test test.cpp && ./test
rm -f test test.cpp
