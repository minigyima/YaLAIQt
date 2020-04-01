#!/bin/bash
# YaLAI Installer: Subzone list maker script
# Copyright minigyima, 2020
zone=$1
touch subzonelist.txt
rm subzonelist.txt
cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "$zone/" | sed "s/$zone\///g" | sort -ud | sort >> subzonelist.txt