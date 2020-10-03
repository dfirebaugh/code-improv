#!/bin/bash

# run hs.rennur_vorpmi, backwards
while read line; do
    eval "set -- $line"
    if [ $# -ge 1 ]; then
        eval "\$$(seq -s ' $' $# -1 1)"
    fi
done < hs.rennur_vorpmi
