#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512
#define name 8

int main(int argc, char *argv[])
{
    // check for 2 args
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //opening the raw
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    // a buffer to hold each 512 bytes
    BYTE buffer[BLOCK_SIZE];
    //counter for printing xxx.jpg
    int counter = 0;
    bool first = false;
    //a jpg file
    FILE *img;
    // the namr of the file
    char filename[name];
    // fread return the number of blocks, if its less than 512 than quit
    while (fread(buffer, BLOCK_SIZE, 1, file))
    {
        // to IF conditions to see if this is a start of a jpg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            if ((buffer[3] & 0xf0) == 0xe0)
            {
                if (first == false)
                {
                    first = true;
                }

                else
                {
                    fclose(img);
                }

                //sprintf prints a string to filename 000,001...
                sprintf(filename, "%03i.jpg", counter++);
                img = fopen(filename, "w");
                if (img == NULL)
                {
                    return 1;
                }
                fwrite(buffer, BLOCK_SIZE, 1, img);
            }
        }

        else if (first == true)
        {

            fwrite(buffer, BLOCK_SIZE, 1, img);
        }

    }

    fclose(img);
    fclose(file);
}
