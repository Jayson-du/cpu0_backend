# !/usr/bash
# -- encode:utf-8 --

find ./ -regex '.*\.\(cpp\|h\|inc\)$' -exec clang-format --style=llvm -i {} \;
