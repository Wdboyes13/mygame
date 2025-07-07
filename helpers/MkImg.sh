#!/bin/sh
set -eux

if [ "$#" -ne 5 ]; then
    echo "Usage: $0 SIZE BGCOLOR TEXTCOLOR TEXT OUTFILE" >&2
    echo "Example: $0 300x100 white black 'Hello' output.png" >&2
    exit 1
fi

SIZE="$1"
BGCOL="$2"
COL="$3"
TXT="$4"
OUT="$5"

magick -size "$SIZE" xc:"$BGCOL" -gravity center \
       -font Helvetica -pointsize 24 -fill "$COL" \
       -annotate +0+0 "$TXT" "$OUT"