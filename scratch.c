#include <stdio.h>
#include "./pset4/bmp/bmp.h"

int main(void)
{
    printf("%i",(4 - (3 * sizeof(RGBTRIPLE)) % 4) % 4);
    return 0;
}
