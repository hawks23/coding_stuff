#Bubble Sort

echo "Enter the limit: "
read n
echo "Enter the numbers"
for(( i=0 ;i<n; i++ ))
do
    read m
    a[i]=$m
done
for(( i=0; i<n; i++ ))
do
    for(( j=0; j<n-i; j++))
    do
    if [ ${a[$j]} -gt ${a[$j+1]} ]
        then
            t=${a[$j]}
            a[$j]=${a[$j+1]}
            a[$j+1]=$t
    fi
    done
done
echo "Sorted array is"
for(( i=0; i<n; i++ ))
    do
    echo -n "${a[$i]} "
done