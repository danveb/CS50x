#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    // since we're handling a 2dimensional array we'll likely need a nested for loop for height/width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // GREEN!
            image[i][j].rgbtGreen = 0xff;
        }
    }
}

// test - $ check50 cs50/labs/2023/x/smiley
// style - $ style50 helpers.c
// submit - $ submit50 cs50/labs/2023/x/smiley