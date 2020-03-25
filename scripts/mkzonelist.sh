#! /bin/bash
touch zonelist.txt
rm zonelist.txt
cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "/" | sed "s/\/.*//g" | sort -ud | sort >> zonelist.txt
