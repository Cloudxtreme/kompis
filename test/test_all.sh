#!/bin/sh
pushd ast
./test.sh
popd
pushd irt
./test.sh
popd
