#!/usr/bin/env bash

for item in ./*.bpl
do
  ./main < $item > "$(echo $item | sed "s/bpl/S/")"
done

for item in ./*.S
do
  gcc -no-pie -c $item
done

for item in ./*.o
do
  rm $item
done