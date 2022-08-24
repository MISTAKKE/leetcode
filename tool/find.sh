#!/bin/bash

if [[ $# -le 0 ]]; then
    echo "Usage: ss xxx or ss xxx ./"
    exit
fi

RESULT=$(grep -rnia $1 $2 --binary-files=without-match |grep -v STL)
if [[ $RESULT != "" ]]; then
    echo "$RESULT"
fi
