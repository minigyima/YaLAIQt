#!/bin/bash
touch keymaps.txt
rm keymaps.txt
localectl list-keymaps > keymaps.txt
