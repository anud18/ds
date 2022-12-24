#!/bin/bash

read -p "Please input a num" F
for((i=1;i<=F;i++))
do
        ./ASA >> A1.out
    sleep 5
        ./btree >> B1.out
    sleep 5
        ./skiplist >> S1.out
    sleep 5
        ./treap >> T1.out
    sleep 5
        ./hashTable >> H1.out
    echo i
done
echo "Finished!!!"
