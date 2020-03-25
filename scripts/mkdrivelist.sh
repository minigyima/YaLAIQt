#!/bin/bash
touch drives.txt
rm drives.txt
touch list.txt
rm list.txt
lsblk -lno NAME,TYPE | grep disk | rev | cut -c 6- | rev > drives.txt
input="drives.txt"
while IFS= read -r line
do
  dir=$(pwd)
  cd /sys/class/block/$line
  cd device
  model=$(cat model)
  size=$(lsblk -lno NAME,SIZE | grep -w $line | cut -c 10-)
  cd $dir
  model=`echo $model | sed 's/ *$//g'`
  size=`echo $size | sed 's/ *$//g'`
  line=`echo $line | sed 's/ *$//g'`
  echo "$model ($line, $size)" >> list.txt
done < "$input"