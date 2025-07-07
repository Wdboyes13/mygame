#include "Numbers.h"
#include <stdio.h>


SDL_Texture* GetSprite(int num){
    switch (num){
        case 0: return sprite0;
        case 1: return sprite1;
        case 2: return sprite2;
        case 3: return sprite3; 
        case 4: return sprite4;
        case 5: return sprite5;
        case 6: return sprite6; 
        case 7: return sprite7; 
        case 8: return sprite8; 
        case 9: return sprite9; 
        default: return NULL;
    }
}


void Render2DNumber(int Number, SDL_Rect Pos1, SDL_Rect Pos2){
    int digits[10];
    int count = 0;
    int num = Number;

    if (num == 0) {
        digits[count++] = 0;
    } else {
        while (num > 0) {
            digits[count++] = num % 10;
            num /= 10;
        }

        // digits are now reversed (e.g. 1234 → [4, 3, 2, 1])
        // To fix that:
        for (int i = 0; i < count / 2; ++i) {
            int temp = digits[i];
            digits[i] = digits[count - i - 1];
            digits[count - i - 1] = temp;
        }
    }



    if (count >= 1) SDL_RenderCopy(ren, GetSprite(digits[0]), NULL, &Pos1);
    if (count >= 2) SDL_RenderCopy(ren, GetSprite(digits[1]), NULL, &Pos2);
}