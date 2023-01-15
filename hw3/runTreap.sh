#!/bin/bash

read -p "Please input a num" F
for((i=1;i<=F;i++))
do
        ./treap >> T1.out
    sleep 5
    echo i
done
echo "Finished!!!"
