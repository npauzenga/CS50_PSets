#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

//char * decrypt(char* cypherText);

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        printf("Enter an encrypted password\n");
        return 1;
    }
    
    //decrypt(argv);
  
  printf("%s\n", crypt("z", "50")); 
  
  return 0;
}

// Char* -> Char*
// produces password from provided encrypted password (cypherText)
// char * decrypt(char* 50zPJlUFIYY0o) -> caesar
// char * decrypt(char* 50gyRGMzn6mi6) -> cs50

/*char * decrypt(char* cypherText)*/
/*{*/
/*    ... password*/
/*}*/

char * decrypt(char* cypherText)
{
    // loop through cypherText and extract first 2 characters
    
    // run crypt() with those 2 characters as salt
    return password;
}
