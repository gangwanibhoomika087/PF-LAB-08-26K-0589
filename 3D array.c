
#include <stdio.h>

int main()
{
    int A[3][3][3];
    int i, j, k;
    int layerSum, rowSum, colSum;
    int total = 0;
    int max, min;
    int layerMax, layerMin;
    int count = 0;
    double average;

    /* Input all 27 elements */
    printf("Enter 27 elements for the 3x3x3 array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter elements of Layer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &A[i][j][k]);
            }
        }
    }

    /* Initialize maximum and minimum */
    max = A[0][0][0];
    min = A[0][0][0];

    printf("\n========== 3D ARRAY ANALYSIS ==========\n");

    /* Analyze each 2D layer */
    for (i = 0; i < 3; i++)
    {
        layerSum = 0;
        layerMax = A[i][0][0];
        layerMin = A[i][0][0];

        printf("\n---------- Layer %d ----------\n", i + 1);

        /* Display the current layer */
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%5d", A[i][j][k]);
            }
            printf("\n");
        }

        /* Calculate layer total, min and max */
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                layerSum += A[i][j][k];
                total += A[i][j][k];
                count++;

                if (A[i][j][k] > max)
                    max = A[i][j][k];

                if (A[i][j][k] < min)
                    min = A[i][j][k];

                if (A[i][j][k] > layerMax)
                    layerMax = A[i][j][k];

                if (A[i][j][k] < layerMin)
                    layerMin = A[i][j][k];
            }
        }

        printf("Layer Total   = %d\n", layerSum);
        printf("Layer Average = %.2f\n", layerSum / 9.0);
        printf("Layer Maximum = %d\n", layerMax);
        printf("Layer Minimum = %d\n", layerMin);

        /* Calculate each row total */
        printf("Row Totals:\n");

        for (j = 0; j < 3; j++)
        {
            rowSum = 0;

            for (k = 0; k < 3; k++)
                rowSum += A[i][j][k];

            printf("Row %d = %d\n", j + 1, rowSum);
        }

        /* Calculate each column total */
        printf("Column Totals:\n");

        for (k = 0; k < 3; k++)
        {
            colSum = 0;

            for (j = 0; j < 3; j++)
                colSum += A[i][j][k];

            printf("Column %d = %d\n", k + 1, colSum);
        }
    }

    /* Overall data insights */
    average = (double)total / count;

    printf("\n========== OVERALL RESULTS ==========\n");
    printf("Total Elements = %d\n", count);
    printf("Overall Sum    = %d\n", total);
    printf("Overall Average= %.2f\n", average);
    printf("Overall Maximum= %d\n", max);
    printf("Overall Minimum= %d\n", min);
    printf("Overall Range  = %d\n", max - min);

    printf("\nAnalysis completed successfully.\n");

    return 0;
}
