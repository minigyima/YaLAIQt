#!/bin/bash
# YaLAI Installer: Locale list maker script
# Copyright minigyima, 2020
touch locales.txt
rm locales.txt
cat /etc/locale.gen | grep -v "#  " | sed 's/#//g' | sed 's/ UTF-8//g' | grep .UTF-8 > locales.txt