#!/bin/sh

echo "Enter first number :"
read num1
echo "Enter second number :"
read num2

for i in {1..5}
do
   echo "\n"
done

echo "Sum is "
echo $(expr $num1 + $num2)