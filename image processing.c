#include <stdio.h>

int main()
{
    int image[4][4];
    int result[4][4];
    int brightness, threshold;
    int i, j, k, l;
    int sum, average, temp, value;

    printf("Enter 16 pixel values (0-255):\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            do
            {
                printf("Enter pixel [%d][%d]: ", i, j);
                scanf("%d", &image[i][j]);

                if (image[i][j] < 0 || image[i][j] > 255)
                {
                    printf("Invalid pixel! Enter a value from 0 to 255.\n");
                }

            } while (image[i][j] < 0 || image[i][j] > 255);
        }
    }

    printf("Enter brightness amount: ");
    scanf("%d", &brightness);

    printf("Enter threshold value (0-255): ");
    scanf("%d", &threshold);

    if (threshold < 0 || threshold > 255)
    {
        printf("Invalid threshold!\n");
        return 0;
    }

    printf("\nOriginal Image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%4d", image[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightness Adjusted Image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            value = image[i][j] + brightness;

            if (value > 255)
                value = 255;
            else if (value < 0)
                value = 0;

            printf("%4d", value);
        }
        printf("\n");
    }

    printf("\nBlack and White Image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (image[i][j] >= threshold)
                printf("%4d", 255);
            else
                printf("%4d", 0);
        }
        printf("\n");
    }

    printf("\nHorizontally Flipped Image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%4d", image[i][3 - j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result[i][j] = image[i][j];
        }
    }

    // Use the original image for every average so changed pixels do not affect later calculations.
    for (i = 1; i < 3; i++)
    {
        for (j = 1; j < 3; j++)
        {
            sum = 0;

            for (k = i - 1; k <= i + 1; k++)
            {
                for (l = j - 1; l <= j + 1; l++)
                {
                    sum = sum + image[k][l];
                }
            }

            average = sum / 9;
            result[i][j] = average;
        }
    }

    printf("\nSmoothed Image:\n");

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%4d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
