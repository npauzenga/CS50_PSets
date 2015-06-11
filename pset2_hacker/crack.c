#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <crypt.h>

int main(void)
{
  
  printf("%s\n", crypt("crimson", "50"));  
  
  return 0;
}
