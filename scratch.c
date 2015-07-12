#include <stdio.h>


int main(void)
{
    int jpgNumber = 0;
    
    char jpgTitle[8];
    sprintf(jpgTitle, "%.*i.jpg", 3, jpgNumber);
    printf("%s", jpgTitle);

}
