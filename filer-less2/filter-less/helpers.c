#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // the avg of pixles values
    int avg;
    float avg2;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3;
            avg2 = (float)(image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3;

            if (avg2 - avg > 0.5)
            {
                avg++;
            }

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // define some variables
    int originalRed, originalGreen, originalBlue;
    int SepiaRed, SepiaGreen, SepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalRed = image[i][j].rgbtRed;
            originalBlue = image[i][j].rgbtBlue;
            originalGreen = image[i][j].rgbtGreen;

            // red
            SepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            if (SepiaRed > 255)
            {
                SepiaRed = 255;
            }

            // blue
            SepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            if (SepiaBlue > 255)
            {
                SepiaBlue = 255;
            }

            // green
            SepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            if (SepiaGreen > 255)
            {
                SepiaGreen = 255;
            }

            image[i][j].rgbtRed = SepiaRed;
            image[i][j].rgbtBlue = SepiaBlue;
            image[i][j].rgbtGreen = SepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int Rtemp, Btemp, Gtemp;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            Rtemp = image[i][j].rgbtRed;
            Btemp = image[i][j].rgbtBlue;
            Gtemp = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;

            image[i][width - 1 - j].rgbtRed = Rtemp;
            ;
            image[i][width - 1 - j].rgbtBlue = Btemp;
            image[i][width - 1 - j].rgbtGreen = Gtemp;
        }
    }

    return;
}


// Blur
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int Gavg, Ravg, Bavg;

    float r, g, b;
    int ar, br, cr;
    int cells = 1;
    RGBTRIPLE image2[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Ravg = image[i][j].rgbtRed;
            Gavg = image[i][j].rgbtGreen;
            Bavg = image[i][j].rgbtBlue;

            if (i + 1 < height)
            {
                Gavg += image[i + 1][j].rgbtGreen;
                Bavg += image[i + 1][j].rgbtBlue;
                Ravg += image[i + 1][j].rgbtRed;
                cells++;
            }

            if (j + 1 < width)
            {
                Gavg += image[i][j + 1].rgbtGreen;
                Bavg += image[i][j + 1].rgbtBlue;
                Ravg += image[i][j + 1].rgbtRed;
                cells++;
            }

            if (i + 1 < height && j + 1 < width)
            {
                Gavg += image[i + 1][j + 1].rgbtGreen;
                Bavg += image[i + 1][j + 1].rgbtBlue;
                Ravg += image[i + 1][j + 1].rgbtRed;
                cells++;
            }

            if (i + 1 < height && j - 1 >= 0)
            {
                Gavg += image[i + 1][j - 1].rgbtGreen;
                Bavg += image[i + 1][j - 1].rgbtBlue;
                Ravg += image[i + 1][j - 1].rgbtRed;
                cells++;
            }

            if (j - 1 >= 0)
            {
                Gavg += image[i][j - 1].rgbtGreen;
                Bavg += image[i][j - 1].rgbtBlue;
                Ravg += image[i][j - 1].rgbtRed;
                cells++;
            }

            if (i - 1 >= 0 && j - 1 >= 0)
            {
                Gavg += image[i - 1][j - 1].rgbtGreen;
                Bavg += image[i - 1][j - 1].rgbtBlue;
                Ravg += image[i - 1][j - 1].rgbtRed;
                cells++;
            }

            if (i - 1 >= 0)
            {
                Gavg += image[i - 1][j].rgbtGreen;
                Bavg += image[i - 1][j].rgbtBlue;
                Ravg += image[i - 1][j].rgbtRed;
                cells++;
            }

            if (i - 1 >= 0 && j + 1 < width)
            {
                Gavg += image[i - 1][j + 1].rgbtGreen;
                Bavg += image[i - 1][j + 1].rgbtBlue;
                Ravg += image[i - 1][j + 1].rgbtRed;
                cells++;
            }

            r = (float)Ravg / cells;
            g = (float)Gavg / cells;
            b = (float)Bavg / cells;

            ar = Ravg / cells;
            br = Gavg / cells;
            cr = Bavg / cells;
            Ravg = ar;
            Gavg = br;
            Bavg = cr;

            if (r - ar >= 0.5)
            {
                ar++;
                Ravg = ar;
            }

            if (g - br >= 0.5)
            {
                br++;
                Gavg = br;
            }
            if (b - cr >= 0.5)
            {
                cr++;
                Bavg = cr;
            }

            image2[i][j].rgbtRed = Ravg;
            image2[i][j].rgbtGreen = Gavg;
            image2[i][j].rgbtBlue = Bavg;

            cells = 1;
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image2[i][j];
        }
    }
    return;
}
