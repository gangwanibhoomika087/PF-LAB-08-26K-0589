#include <stdio.h>

int main()
{
    int stock[3][4];
    int i, j;
    int total, grandTotal = 0;
    int greatestTotal = 0, greatestAisle = 0;
    int emptyShelves = 0;

    printf("Enter stock for 3 aisles and 4 shelf positions:\n");

    for (i = 0; i < 3; i++)
    {
        printf("\nAisle %d:\n", i + 1);

        for (j = 0; j < 4; j++)
        {
            printf("Enter units at position %d: ", j + 1);
            scanf("%d", &stock[i][j]);
        }
    }

    printf("\nOriginal Stock Grid:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", stock[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;

        for (j = 0; j < 4; j++)
        {
            total = total + stock[i][j];
        }

        if (i == 0 || total > greatestTotal)
        {
            greatestTotal = total;
            greatestAisle = i;
        }
    }

    printf("\nAisle with greatest stock: Aisle %d", greatestAisle + 1);
    printf("\nTotal stock in this aisle: %d\n", greatestTotal);

    printf("\nLow Stock Alerts:\n");

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                printf("Aisle %d, Position %d: %d units\n",
                       i + 1, j + 1, stock[i][j]);
            }

            if (stock[i][j] == 0)
            {
                emptyShelves++;
            }
        }
    }

    printf("\nCompletely empty shelves: %d\n", emptyShelves);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                stock[i][j] = stock[i][j] + 10;
            }
        }
    }

    printf("\nStock Grid After Restocking:\n");

    grandTotal = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", stock[i][j]);
            grandTotal = grandTotal + stock[i][j];
        }
        printf("\n");
    }

    printf("\nNew Grand Total of Units: %d\n", grandTotal);

    return 0;
}
