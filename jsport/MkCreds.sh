#!/bin/sh
set -eu

FONT="Helvetica"
SIZE="800x650"
OUT="credits.png"
PTSIZE=20
BGCOLOR="black"
FGCOLOR="white"


TEXT=$(cat credtxt.txt)


magick -size "$SIZE" xc:"$BGCOLOR" \
    -fill "$FGCOLOR" -font "$FONT" -pointsize "$PTSIZE" \
    -gravity NorthWest -annotate +20+20 "$TEXT" \
    "$OUT"