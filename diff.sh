#!/bin/sh

set -x
set -e

OPT=${OPT:--O3}
ASM=${ASM:-}
INC="-I. -IInclude"
FLAGS="$OPT $INC"

gcc $FLAGS main.c -o main
gcc $FLAGS $ASM -S main.c -o main.s

gcc $FLAGS -DBRANCHELESS main.c -o main-brancheless
gcc $FLAGS $ASM -DBRANCHELESS -S main.c -o main-brancheless.s

time ./main
time ./main-brancheless
