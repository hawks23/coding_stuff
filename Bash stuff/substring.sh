#!/bin/bash  
#Script to extract first 10 characters of a string  
  

str="Hello World."  
substr="${str:0:10}"  
echo "Substring : $substr"  