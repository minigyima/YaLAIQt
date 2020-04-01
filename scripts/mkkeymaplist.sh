#!/bin/bash
# YaLAI Installer: Keymap list maker script
# Copyright minigyima, 2020
touch keymaps.txt
rm keymaps.txt
localectl list-keymaps > keymaps.txt
