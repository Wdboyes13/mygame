#!/bin/sh
set -eux

SIZE="340x150"
BGCOL="black"
COL="white"
TXT="$(cat <<EOF
Press Space to Start
Press C to View Credits
Press P to start music
EOF
)"
OUT="menutxt.png"

magick -size "$SIZE" xc:"$BGCOL" -gravity center \
       -font Helvetica -pointsize 24 -fill "$COL" \
       -annotate +0+0 "$TXT" "$OUT"