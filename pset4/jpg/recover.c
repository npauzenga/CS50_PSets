#include <stdio.h>
#include <stdlib.h>

#include "jpg.h"

/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

int main(int argc, char* argv[])
{
    // open memory card file
    FILE* memCard = fopen("card.raw", "r");
    
    // TODO allocate memory

 
    // temp storage - array of type BYTE, 512 BYTES long
    char buffer[512];
    char jpgTitle[8];
    int jpgNumber = 0;
    
    FILE* img;
    
    // read from the memCard, 512 bytes at a time 
    while(fread(&buffer, sizeof(BYTE), 512, memCard) == 512)
    {
        // if the first four BYTES of the buffer == JPG
        if (buffer[0] == (char)0xff && buffer[1] == (char)0xd8 && buffer[2] == (char)0xff)
        {
            if (buffer[3] == (char)0xe0 || buffer[3] == (char)0xe1)
            {
                // check if we have started writing jpgs
                if (jpgNumber > 0)
                {
                    fclose(img);
                }
                
                // print the name of the file to jpgTitle and open an img
                // with that name, then write buffer until new jpg is found
                jpgNumber++;
                sprintf(jpgTitle, "%.*i.jpg", 3, jpgNumber);
                
                img = fopen(jpgTitle, "w");
                
                fwrite(&buffer, sizeof(BYTE), 512, img);
            }
        }
        
        else if (jpgNumber != 000)
        {
            fwrite(&buffer, sizeof(buffer), 1, img);
        }
    }
    
    fclose(memCard);
    fclose(img);
    
    // TODO free memory
    
    return 0;

}
