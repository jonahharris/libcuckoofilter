#!/bin/bash
gcc -Wall -O0 -g3 -I./include src/cuckoo_filter.c tests/cuckootest.c -o test
gcc -Wall -O0 -g3 -I./include src/cuckoo_filter.c tests/cuckootest2.c -o test2

