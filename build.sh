#!/bin/bash

rm -rf ./log/

bazel build --cxxopt='-std=c++17' src:main
