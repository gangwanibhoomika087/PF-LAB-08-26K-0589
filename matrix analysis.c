
#include <stdio.h>

int main()
{
    int A[3][3], T[3][3], C[3][3];
    int adj[3][3];
    int i, j, k, l;
    int det = 0, minor, sign, temp;
    float inv[3][3];

    printf("Enter the elements of 3x3 matrix:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nOriginal Matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }

    /* 1. Transpose */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            T[i][j] = A[j][i];
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", T[i][j]);
        printf("\n");
    }

    /* 2. Determinant using first-row expansion */
    for (j = 0; j < 3; j++)
    {
        int x[2], y[2], p = 0, q = 0;

        for (k = 1; k < 3; k++)
            x[p++] = k;

        for (k = 0; k < 3; k++)
            if (k != j)
                y[q++] = k;

        minor = A[x[0]][y[0]] * A[x[1]][y[1]]
              - A[x[0]][y[1]] * A[x[1]][y[0]];

        if (j % 2 == 0)
            det += A[0][j] * minor;
        else
            det -= A[0][j] * minor;
    }

    printf("\nDeterminant = %d\n", det);

    /* 3. Cofactor Matrix */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            int r[2], c[2], p = 0, q = 0;

            for (k = 0; k < 3; k++)
                if (k != i)
                    r[p++] = k;

            for (k = 0; k < 3; k++)
                if (k != j)
                    c[q++] = k;

            minor = A[r[0]][c[0]] * A[r[1]][c[1]]
                  - A[r[0]][c[1]] * A[r[1]][c[0]];

            sign = ((i + j) % 2 == 0) ? 1 : -1;
            C[i][j] = sign * minor;
        }
    }

    printf("\nCofactor Matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", C[i][j]);
        printf("\n");
    }

    /* 4. Adjoint = Transpose of cofactor matrix */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            adj[i][j] = C[j][i];
    }

    printf("\nAdjoint Matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }

    /* 5. Inverse = Adjoint / Determinant */
    if (det == 0)
    {
        printf("\nInverse does not exist because determinant is zero.\n");
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
                inv[i][j] = (float)adj[i][j] / det;
        }

        printf("\nInverse Matrix:\n");
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
                printf("%10.3f", inv[i][j]);
            printf("\n");
        }
    }

    return 0;
}
