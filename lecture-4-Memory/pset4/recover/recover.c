#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Program accepts exactly one command-line argument, name of forensic image from which to recover JPEG's
// if program is not executed with one command-line argument, it should remind user of correct usage, and "main" should return 1
// if forensic image cannot be opened for reading, program should inform user as much, and main should return 1
// files should be named ###.jpg, where ### is 3 digit decimal number, starting 000
// program, if using malloc must NOT leak any memory & use free to free up allocated memory

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // ensure proper usage with argc != 2 (just 1 command-line argument)
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(argv[1], "r");

    // check: if input file can't be opened exit 2
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", argv[1]);
        return 2;
    }

    // declare BYTE buffer to store 512 bytes
    BYTE buffer[512];

    // initialize count_image at 0
    int count_image = 0;

    // Uninitialize file pointer to use output data from input file
    FILE *outptr = NULL;

    // allocate memory using malloc
    char *filename = malloc(8 * sizeof(char));

    // read 512 bytes from inptr and store on buffer
    while (fread(buffer, sizeof(BYTE) * 512, 1, inptr) == 1)
    {
        // check if bytes is start of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }
            sprintf(filename, "%03d.jpg", count_image++);
            outptr = fopen(filename, "w");
        }

        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE) * 512, 1, outptr);
        }
    }

    if (outptr != NULL)
    {
        fclose(outptr);
    }
    fclose(inptr);
    free(filename);
    return 0;
}

// test - $ check50 cs50/problems/2023/x/recover
// style - $ style50 recover.c
// submit - $ submit50 cs50/problems/2023/x/recover