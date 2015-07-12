#include <stdint.h>


typedef uint8_t  BYTE;

typedef struct
{
    BYTE header1;
    BYTE header2;
    BYTE header3;
    BYTE header4;
} __attribute__((__packed__))
JPGHEADER;

