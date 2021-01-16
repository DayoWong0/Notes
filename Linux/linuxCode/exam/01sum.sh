#!/bin/bash
sum=0    
for i in $*       #（$*表示所有参数）
do  
sum=$((sum+i))

done
echo $sum