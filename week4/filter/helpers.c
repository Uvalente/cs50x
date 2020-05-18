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
            unsigned char average_color = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float)3);

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
    RGBTRIPLE copy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_blue = 0x00;
            int average_red = 0x00;
            int average_green = 0x00;
            float divisor = 0;
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if ((i == 0 && k == -1) || (j == 0 && l == -1) || (j == width - 1 && l == 1) || (i == height - 1 && k == 1))
                    {
                        continue;
                    }
                    else
                    {
                        divisor++;
                        average_blue += copy_image[i + k][j + l].rgbtBlue;
                        average_red += copy_image[i + k][j + l].rgbtRed;
                        average_green += copy_image[i + k][j + l].rgbtGreen;
                    }                    
                }

            }
            image[i][j].rgbtBlue = round(average_blue / divisor);
            image[i][j].rgbtRed = round(average_red / divisor);
            image[i][j].rgbtGreen = round(average_green / divisor);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy_image[i][j] = image[i][j];
        }
    }

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
                        orizontal_edge_blue += copy_image[i + k][j + l].rgbtBlue * Gx[matrix_count];

                        vertical_edge_blue += copy_image[i + k][j + l].rgbtBlue * Gy[matrix_count];

                        orizontal_edge_red += copy_image[i + k][j + l].rgbtRed * Gx[matrix_count];
                        vertical_edge_red += copy_image[i + k][j + l].rgbtRed * Gy[matrix_count];

                        orizontal_edge_green += copy_image[i + k][j + l].rgbtGreen * Gx[matrix_count];
                        vertical_edge_green += copy_image[i + k][j + l].rgbtGreen * Gy[matrix_count];

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

            image[i][j].rgbtBlue = blue;

            image[i][j].rgbtRed = red;

            image[i][j].rgbtGreen = green;
        }
    }
    return;
}
