#include "helpers.h"
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            unsigned char average_color = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;

            image[i][j].rgbtBlue = average_color;
            image[i][j].rgbtGreen = average_color;
            image[i][j].rgbtRed = average_color;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int limit = width - 1;
        for (int j = 0; j < limit; j++, limit--)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][limit];
            image[i][limit] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            long average_blue = 0x00;
            long average_red = 0x00;
            long average_green = 0x00;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i == 0 || j == 0) && (k == -1 || l == -1))
                    {
                        continue;
                    }
                    else
                    {
                        average_blue += image[i + k][j + l].rgbtBlue;
                        average_red += image[i + k][j + l].rgbtRed;
                        average_green += image[i + k][j + l].rgbtGreen;
                    }                    
                }

            }
            image[i][j].rgbtBlue = average_blue / 9;
            image[i][j].rgbtRed = average_red / 9;
            image[i][j].rgbtGreen = average_green / 9;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
