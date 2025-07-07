MakeNum(){
    Num=$1
    magick -size 25x50 xc:black -gravity center \
    -font Helvetica -pointsize 24 -fill white -annotate +0+0 "$Num" "$Num.png"
}

MakeNum 1
MakeNum 2
MakeNum 3
MakeNum 4
MakeNum 5
MakeNum 6
MakeNum 7
MakeNum 8
MakeNum 9
MakeNum 0