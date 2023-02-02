#include "helpers.h"
#include <math.h>

// Convert image to grayscale
// RGB values need to be equal (darker to lighter)
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // nested for loops to work on height/width
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // since all values are integers we should round float-point numbers (3.0 since RGB -> 3 colors)
            // set rgbtRed, rgbtGreen, rgbtBlue to equal each other
            // make sure rgbt variable is at end; else returns C error
            int rgbt = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = rgbt;
        }
    }
    return;
}

// Convert image to sepia
// sepia (old-timey, reddish-brown) version of same image
// sepia formula to take original RGB and determines new sepia value
// sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
// sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
// sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over height/width arrays (nested for loop)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // initialize int vars for RGB; keeps code DRY with sepia formula
            int rgbRed = image[i][j].rgbtRed;
            int rgbGreen = image[i][j].rgbtGreen;
            int rgbBlue = image[i][j].rgbtBlue;

            // initialize int with sepia formula for each; making sure to round
            int sepiaRed = round((.393 * rgbRed + .769 * rgbGreen + .189 * rgbBlue));
            int sepiaGreen = round((.349 * rgbRed + .686 * rgbGreen + .168 * rgbBlue));
            int sepiaBlue = round((.272 * rgbRed + .534 * rgbGreen + .131 * rgbBlue));

            // check: if result of each sepia value is > 255? we'll cap at 255
            // use a ternary operator to simplify code and set correctly rgbt values
            image[i][j].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][j].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally -> produce a mirror image of itself
// take each row and reverse it (1st with last, 2nd with 2nd to last, etc.)
// if array is EVEN we know all values must be swapped
// if array is ODD we know mid value will stay at same position
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // iterate over height
    for (int i = 0; i < height; i++)
    {
        // check: if width is even?
        // key is to use modulo % 2 to check even or odd; even == 0; odd !== 0
        if (width % 2 == 0)
        {
            // iterate over the width
            for (int j = 0; j < width/2; j++)
            {
                // instantiate temp var from RGBTRIPLE struct and begin swapping
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width-(j + 1)];
                image[i][width-(j+1)] = temp[i][j];
            }
        }
        // else if width is ODD?
        else if (width % 2 != 0)
        {
            for (int j = 0; j < (width-1)/2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width-(j + 1)];
                image[i][width-(j + 1)] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
// blur: box-blurred version, softer details
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // instantiate temp var from RGBTRIPLE struct
    RGBTRIPLE temp[height][width];

    // iterate over height (i at 0 until end)
    for (int i = 0; i < height; i++)
    {
        // iterate over width (j at 0 until end)
        for (int j = 0; j < width; j++)
        {
            // initialize floats for RGB, count at 0
            float sumRed = 0;
            float sumGreen = 0;
            float sumBlue = 0;
            float count = 0;

            for (int r = -1; r < 2; r++)
            {
                for (int c = -1; c < 2; c++)
                {
                    if (i + r < 0 || i + r > height - 1) continue;
                    if (j + c < 0 || j + c > width - 1) continue;

                    sumRed += image[i + r][j + c].rgbtRed;
                    sumGreen += image[i + r][j + c].rgbtGreen;
                    sumBlue += image[i + r][j + c].rgbtBlue;
                    count++;
                }
            }

            temp[i][j].rgbtRed = round(sumRed / count);
            temp[i][j].rgbtGreen = round(sumGreen / count);
            temp[i][j].rgbtBlue = round(sumBlue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;

        }
    }
    return;
}

// test - $ check50 cs50/problems/2023/x/filter/less
// style - $ style50 helpers.c
// submit - $ submit50 cs50/problems/2023/x/filter/less