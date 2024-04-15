#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            float average = (image[row][col].rgbtBlue + image[row][col].rgbtRed + image[row][col].rgbtGreen)/3.00;
            int avg = round(average);
            image[row][col].rgbtBlue = avg;
            image[row][col].rgbtRed = avg;
            image[row][col].rgbtGreen = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int sepiaRed = round(.393 * image[row][col].rgbtRed + .769 * image[row][col].rgbtGreen + .189 * image[row][col].rgbtBlue);
            int sepiaGreen = round(.349 * image[row][col].rgbtRed + .686 * image[row][col].rgbtGreen + .168 * image[row][col].rgbtBlue);
            int sepiaBlue = round(.272 * image[row][col].rgbtRed + .534 * image[row][col].rgbtGreen + .131 * image[row][col].rgbtBlue);
            image[row][col].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
            image[row][col].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[row][col].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++)
        {
            for(int col = 0; col < (width/2); col++)
            {
                int red = image[row][col].rgbtRed;
                int blue = image[row][col].rgbtBlue;
                int green = image[row][col].rgbtGreen;
                image[row][col].rgbtRed = image[row][width - col - 1].rgbtRed;
                image[row][col].rgbtBlue = image[row][width - col - 1].rgbtBlue;
                image[row][col].rgbtGreen = image[row][width - col - 1].rgbtGreen;
                image[row][width-col-1].rgbtRed = red;
                image[row][width-col-1].rgbtBlue = blue;
                image[row][width-col-1].rgbtGreen = green;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempy[height][width];

    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            int sumyBlue = 0;
            int sumyRed = 0;
            int sumyGreen = 0;
            float counterx = 0.00;
            for(int x = -1; x < 2; x++)
            {
                for(int y = -1; y < 2; y++)
                {
                    if(row + x < 0 || row + x > height -1 || col + y < 0 || col + y > width -1)
                    {
                        continue;
                    }
                    sumyBlue += image[row + x][col + y].rgbtBlue;
                    sumyRed += image[row + x][col + y].rgbtRed;
                    sumyGreen += image[row + x][col + y].rgbtGreen;
                    counterx += 1;
                }
            }
            tempy[row][col].rgbtBlue = round(sumyBlue/counterx);
            tempy[row][col].rgbtGreen = round(sumyGreen/counterx);
            tempy[row][col].rgbtRed = round(sumyRed/counterx);
        }
    }
    for(int row = 0; row < height; row++)
    {
        for(int col = 0; col < width; col++)
        {
            image[row][col].rgbtBlue = tempy[row][col].rgbtBlue;
            image[row][col].rgbtRed = tempy[row][col].rgbtRed;
            image[row][col].rgbtGreen = tempy[row][col].rgbtGreen;
        }
    }
    return;
}
