#!/bin/bash

if [[ $# -lt 1 ]];
then
    echo "usage $0 <program>"
else
    perf record -F 99 -g -- "$1"
    perf script | stackcollapse-perf.pl | flamegraph.pl > perf.svg
fi