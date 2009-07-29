#!/bin/sh
./cxxtest/cxxtestgen.pl --error-printer -o test.cpp test_ast_pp.hpp && g++ -Wall -I./cxxtest -I../../src -o test test.cpp ../../src/ast/*.cpp && ./test
rm -f test test.cpp
