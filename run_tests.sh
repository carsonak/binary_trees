#!/bin/bash

while read -r line
do test_files+=("$line")
done < <(
    find . -maxdepth 1 -name '[[:digit:]]*.c' -type f | 
    sed -E -e 's/\.\/([[:digit:]]+-)(binary_trees?_|bst_|avl_)?(\w+)\.c$/tests\/bin\/\1\3/'
)

COLOUR_GREEN='\033[1;92m'
COLOUR_OFF='\033[0m'
for file in "${test_files[@]}"
do
    echo -n "Compiling $(basename "$file")..."
    if ! make --silent --jobs="$(nproc)" "$file"
    then exit 1
    fi

    echo -e "$COLOUR_GREEN OK$COLOUR_OFF"
done

for file in "${test_files[@]}"
do
    echo -n "Running test $(basename "$file")..."
    if ! ./"$file" 1> /dev/null
    then exit 1
    fi

    echo -e "$COLOUR_GREEN OK$COLOUR_OFF"
done
