#!/bin/bash
gcc -Wall -std=c99 -fsanitize=address -O2 -g3 -I./include src/cuckoo_filter.c tests/cuckootest.c -o test
gcc -Wall -std=c99 -fsanitize=address -O2 -g3 -I./include src/cuckoo_filter.c tests/cuckootest2.c -o test2

