#!/bin/sh
read a

if [ $(($a % 2)) -ne 0 ]
then
  echo "Odd"
else
  echo "Even"
fi
