#!/bin/bash
while true; do
    ./data > data.in
    ./biao <data.in >std.out
    ./xianlun <data.in >code.out
    if diff std.out code.out; then
        printf "AC\n"
    else
        printf "Wa\n"
        exit 0
    fi
done