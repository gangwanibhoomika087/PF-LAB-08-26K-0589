
#include <stdio.h>

int main()
{
    int A[3][3][3];
    int i, j, k;
    int layer1, layer2;
    int identical;
    int identicalPairs = 0;
    int distinctPairs = 0;

    /* Input elements */
    printf("Enter elements of the 3x3x3 array:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nEnter Layer %d (9 elements):\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &A[i][j][k]);
            }
        }
    }

    /* Display all three layers */
    printf("\n========== MATRIX LAYERS ==========\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nLayer %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 3; k++)
            {
                printf("%5d", A[i][j][k]);
            }
            printf("\n");
        }
    }

    /* Compare every pair of layers */
    printf("\n========== LAYER COMPARISONS ==========\n");

    for (layer1 = 0; layer1 < 3; layer1++)
    {
        for (layer2 = layer1 + 1; layer2 < 3; layer2++)
        {
            identical = 1;

            for (i = 0; i < 3; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    if (A[layer1][i][j] != A[layer2][i][j])
                    {
                        identical = 0;
                    }
                }
            }

            printf("\nComparing Layer %d and Layer %d:\n",
                   layer1 + 1, layer2 + 1);

            if (identical)
            {
                printf("Result: Layers are IDENTICAL.\n");
                identicalPairs++;
            }
            else
            {
                printf("Result: Layers are DISTINCT.\n");
                distinctPairs++;
            }
        }
    }

    /* Overall results */
    printf("\n========== FINAL REPORT ==========\n");
    printf("Total comparisons : 3\n");
    printf("Identical pairs   : %d\n", identicalPairs);
    printf("Distinct pairs    : %d\n", distinctPairs);

    if (identicalPairs == 3)
    {
        printf("All layers are identical.\n");
    }
    else if (distinctPairs == 3)
    {
        printf("All layers are distinct from each other.\n");
    }
    else
    {
        printf("Some layers are identical and others are distinct.\n");
    }

    return 0;
}
