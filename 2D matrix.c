
#include <stdio.h>
#include <math.h>

#define MAX 5
#define EPS 0.000001

/* Check whether a matrix is zero */
int isZero(double A[MAX][MAX], int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (fabs(A[i][j]) > EPS)
                return 0;

    return 1;
}

/* Matrix multiplication */
void multiply(double A[MAX][MAX],
              double B[MAX][MAX],
              double P[MAX][MAX], int n)
{
    int i, j, k;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            P[i][j] = 0;

            for (k = 0; k < n; k++)
                P[i][j] += A[i][k] * B[k][j];
        }
}

/* Check whether two matrices are equal */
int equal(double A[MAX][MAX], double B[MAX][MAX],
          int r, int c)
{
    int i, j;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (fabs(A[i][j] - B[i][j]) > EPS)
                return 0;

    return 1;
}

/* Calculate determinant using Gaussian elimination */
double determinant(double A[MAX][MAX], int n)
{
    double T[MAX][MAX], det = 1.0;
    double factor, temp, maxVal;
    int i, j, k, pivot;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            T[i][j] = A[i][j];

    for (i = 0; i < n; i++)
    {
        pivot = i;
        maxVal = fabs(T[i][i]);

        for (j = i + 1; j < n; j++)
            if (fabs(T[j][i]) > maxVal)
            {
                maxVal = fabs(T[j][i]);
                pivot = j;
            }

        if (maxVal < EPS)
            return 0.0;

        if (pivot != i)
        {
            for (j = 0; j < n; j++)
            {
                temp = T[i][j];
                T[i][j] = T[pivot][j];
                T[pivot][j] = temp;
            }

            det = -det;
        }

        det *= T[i][i];

        for (k = i + 1; k < n; k++)
        {
            factor = T[k][i] / T[i][i];

            for (j = i + 1; j < n; j++)
                T[k][j] -= factor * T[i][j];

            T[k][i] = 0;
        }
    }

    return det;
}

int main(void)
{
    double A[MAX][MAX], B[MAX][MAX];
    double P[MAX][MAX], Q[MAX][MAX];
    double det;
    int r, c, br, bc;
    int i, j, k;
    int zero, identity, diagonal, scalar;
    int upper, lower, symmetric, skew;
    int idempotent, nilpotent, found;
    char choice;

    printf("Enter number of rows (1-5): ");
    scanf("%d", &r);

    printf("Enter number of columns (1-5): ");
    scanf("%d", &c);

    if (r < 1 || r > 5 || c < 1 || c > 5)
    {
        printf("Invalid matrix dimensions!\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%lf", &A[i][j]);

    printf("\nEntered Matrix:\n");

    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%8.2f", A[i][j]);

        printf("\n");
    }

    printf("\n--- MATRIX ANALYSIS ---\n");

    /* 1 and 2: Square or rectangular */
    if (r == c)
        printf("1. Square Matrix\n");
    else
        printf("2. Rectangular Matrix\n");

    /* 3 and 15: Zero and null matrix */
    zero = isZero(A, r, c);

    if (zero)
    {
        printf("3. Zero Matrix\n");
        printf("15. Null Matrix\n");
    }

    /* 13: Row matrix */
    if (r == 1)
        printf("13. Row Matrix\n");

    /* 14: Column matrix */
    if (c == 1)
        printf("14. Column Matrix\n");

    if (r == c)
    {
        diagonal = 1;
        scalar = 1;
        identity = 1;
        upper = 1;
        lower = 1;
        symmetric = 1;
        skew = 1;

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if (i != j && fabs(A[i][j]) > EPS)
                {
                    diagonal = 0;
                    upper = (j < i) ? 0 : upper;
                    lower = (j > i) ? 0 : lower;
                    identity = 0;
                    scalar = 0;
                }

                if (i == j)
                {
                    if (fabs(A[i][i] - 1.0) > EPS)
                        identity = 0;

                    if (fabs(A[i][i] - A[0][0]) > EPS)
                        scalar = 0;

                    if (fabs(A[i][i]) > EPS)
                        skew = 0;
                }

                if (fabs(A[i][j] - A[j][i]) > EPS)
                    symmetric = 0;

                if (fabs(A[i][j] + A[j][i]) > EPS)
                    skew = 0;
            }
        }

        /* 4-10: Square matrix classifications */
        if (identity)
            printf("4. Identity Matrix\n");

        if (diagonal)
            printf("5. Diagonal Matrix\n");

        if (scalar)
            printf("6. Scalar Matrix\n");

        if (upper)
            printf("7. Upper Triangular Matrix\n");

        if (lower)
            printf("8. Lower Triangular Matrix\n");

        if (symmetric)
            printf("9. Symmetric Matrix\n");

        if (skew)
            printf("10. Skew-Symmetric Matrix\n");

        /* 11: Singular or non-singular */
        det = determinant(A, r);

        printf("Determinant = %.4f\n", det);

        if (fabs(det) < EPS)
            printf("11. Singular Matrix\n");
        else
            printf("11. Non-Singular Matrix\n");

        /* 16: Idempotent, A*A = A */
        multiply(A, A, P, r);

        idempotent = equal(A, P, r, r);

        if (idempotent)
            printf("16. Idempotent Matrix\n");

        /* 17: Nilpotent, A^k = 0 for some positive k */
        for (i = 0; i < r; i++)
            for (j = 0; j < r; j++)
                P[i][j] = A[i][j];

        nilpotent = 0;
        found = 0;

        for (k = 1; k <= r; k++)
        {
            if (isZero(P, r, r))
            {
                nilpotent = 1;
                found = 1;
                break;
            }

            multiply(P, A, Q, r);

            for (i = 0; i < r; i++)
                for (j = 0; j < r; j++)
                    P[i][j] = Q[i][j];
        }

        if (nilpotent || isZero(P, r, r))
            printf("17. Nilpotent Matrix\n");
    }

    /* 12: Compare with another matrix */
    printf("\nDo you want to compare another matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("Enter rows and columns of second matrix: ");
        scanf("%d %d", &br, &bc);

        if (br < 1 || br > 5 || bc < 1 || bc > 5)
        {
            printf("Invalid second matrix dimensions!\n");
            return 1;
        }

        printf("Enter second matrix elements:\n");

        for (i = 0; i < br; i++)
            for (j = 0; j < bc; j++)
                scanf("%lf", &B[i][j]);

        if (r == br && c == bc && equal(A, B, r, c))
            printf("12. Matrices are Equal\n");
        else
            printf("12. Matrices are NOT Equal\n");
    }

    printf("\nMatrix analysis completed.\n");

    return 0;
}
