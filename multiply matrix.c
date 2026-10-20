
#include <stdio.h>

int main()
{
    int A[3][3], B[3][3], C[3][3];
    int r1, c1, r2, c2;
    int i, j, k;

    /* Input dimensions */
    printf("Enter rows and columns of Matrix A (max 3x3): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of Matrix B (max 3x3): ");
    scanf("%d %d", &r2, &c2);

    /* Validate dimensions */
    if (r1 < 1 || r1 > 3 || c1 < 1 || c1 > 3 ||
        r2 < 1 || r2 > 3 || c2 < 1 || c2 > 3)
    {
        printf("Error: Matrix dimensions must be between 1 and 3.\n");
        return 1;
    }

    /* Check multiplication compatibility */
    if (c1 != r2)
    {
        printf("Error: Matrix multiplication is not possible.\n");
        printf("Columns of A must equal rows of B.\n");
        return 1;
    }

    /* Input Matrix A */
    printf("\nEnter elements of Matrix A:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    /* Input Matrix B */
    printf("\nEnter elements of Matrix B:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    /* Initialize result matrix */
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            C[i][j] = 0;
        }
    }

    /* Matrix multiplication using three nested loops */
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            for (k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    /* Display Matrix A */
    printf("\nMatrix A:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%5d", A[i][j]);
        }
        printf("\n");
    }

    /* Display Matrix B */
    printf("\nMatrix B:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%5d", B[i][j]);
        }
        printf("\n");
    }

    /* Display result */
    printf("\nResult of A x B:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%5d", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
