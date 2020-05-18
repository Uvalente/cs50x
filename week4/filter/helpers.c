#include "helpers.h"
#include <stdio.h>
#include <math.h>

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
    // image copy
    
    for (int i = 0; i < height; i++)
    {
        // check for -1
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
    // image copy
    RGBTRIPLE image2[height][width];
    int Gx[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int Gy[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    int pixel_count = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            long long orizontal_edge_blue = 0x00;
            long long vertical_edge_blue = 0x00;
            long long orizontal_edge_red = 0x00;
            long long vertical_edge_red = 0x00;
            long long orizontal_edge_green = 0x00;
            long long vertical_edge_green = 0x00;
            int matrix_count = 0;
            // pixel_count++;

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
                        orizontal_edge_blue += image[i + k][j + l].rgbtBlue * Gx[matrix_count];

                        vertical_edge_blue += image[i + k][j + l].rgbtBlue * Gy[matrix_count];

                        orizontal_edge_red += image[i + k][j + l].rgbtRed * Gx[matrix_count];
                        vertical_edge_red += image[i + k][j + l].rgbtRed * Gy[matrix_count];

                        orizontal_edge_green += image[i + k][j + l].rgbtGreen * Gx[matrix_count];
                        vertical_edge_green += image[i + k][j + l].rgbtGreen * Gy[matrix_count];

                        // printf("%d ", Gx[matrix_count]);
                        matrix_count++;
                    }                    
                }

            }
            long long blue = sqrt((orizontal_edge_blue * orizontal_edge_blue) + (vertical_edge_blue * vertical_edge_blue));

            long long red = sqrt((orizontal_edge_red * orizontal_edge_red) + (vertical_edge_red * vertical_edge_red));

            long long green = sqrt((orizontal_edge_green * orizontal_edge_green) + (vertical_edge_green * vertical_edge_green));

            if (blue > 255)
            {
                blue = 255;
            }

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }

            image2[i][j].rgbtBlue = blue;

            // printf("%i ", pixel_count);

            image2[i][j].rgbtRed = red;

            image2[i][j].rgbtGreen = green;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            image[i][j] = image2[i][j];
        }
    }
    return;
}
