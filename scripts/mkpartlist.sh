#!/bin/bash
drive=$1
touch part.txt
rm part.txt
touch partlist.txt
rm partlist.txt
lsblk -lno NAME,TYPE | grep part | grep $drive | rev | cut -c 6- | rev > part.txt
input="part.txt"
while IFS= read -r line
do
  size=$(lsblk -lno NAME,SIZE | grep -w $line | cut -c 10-)
  size=`echo $size | sed 's/ *$//g'`
  line=`echo $line | sed 's/ *$//g'`
  echo "$line ($size)" >> partlist.txt
done < "$input"