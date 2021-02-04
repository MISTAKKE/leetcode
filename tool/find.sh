#!/bin/bash

if [[ $# -le 0 ]]; then
    echo "Usage: ss xxx or ss xxx ./"
    exit
fi

RESULT=$(grep -rnia $1 * |grep cpp)
if [[ $RESULT != "" ]]; then
    echo "$RESULT"
fi
