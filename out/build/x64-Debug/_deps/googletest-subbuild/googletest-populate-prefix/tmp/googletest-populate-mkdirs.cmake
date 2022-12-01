# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-src"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-build"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/Labs/rep/calculator-team-8/out/build/x64-Debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
