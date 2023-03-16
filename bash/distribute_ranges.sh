#!/bin/bash

dfs() {
    local node=$1
    local color=$2
    visited["$node"]=$color

    for neighbor in ${graph["$node"]}; do
        if [ "${visited["$neighbor"]}" -eq "$color" ]; then
            return 1
        fi
        if [ "${visited["$neighbor"]}" -eq 0 ] && ! dfs $neighbor $((3 - color)); then
            return 1
        fi
    done

    return 0
}

read -r n
read -r cols

declare -A intervals
for ((i = 0; i < n; i++)); do
    read -r start end
    intervals["$i"]="$start $end"
done

declare -A graph
for ((i = 0; i < n; i++)); do
    for ((j = i + 1; j < n; j++)); do
        interval_i=(${intervals["$i"]})
        interval_j=(${intervals["$j"]})
        if [ ${interval_i[1]} -ge ${interval_j[0]} ] && [ ${interval_i[0]} -le ${interval_j[1]} ]; then
            graph["$i"]+="$j "
            graph["$j"]+="$i "
        fi
    done
done

declare -A visited
independent_groups=0
M=$((10 ** 9 + 7))

# Initialize visited array with default values of 0
for ((i = 0; i < n; i++)); do
    visited["$i"]=0
done

for ((i = 0; i < n; i++)); do
    if [ "${visited["$i"]}" -eq 0 ]; then
        if ! dfs $i 1; then
            echo 0
            exit 0
        fi
        ((independent_groups++))
    fi
done

result=$(( ( (1 << independent_groups) - 2 ) % M ))
echo $result