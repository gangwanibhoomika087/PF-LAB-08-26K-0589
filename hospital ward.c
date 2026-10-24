#include <stdio.h>

int main()
{
    int beds[2][3][2] = {0};
    int choice;
    int floor, ward, bed, patientID;
    int i, j, k;
    int occupied, vacant;
    int floorOccupied[2] = {0};
    float percentage;
    int wardOccupied;
    int highestWard = 0;
    int highestFloor = 0;
    int highestWardNumber = 0;
    int maxOccupied = -1;

    do
    {
        printf("\n===== HOSPITAL BED MANAGEMENT =====\n");
        printf("1. Admit Patient\n");
        printf("2. Discharge Patient\n");
        printf("3. Occupancy Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter floor (1-2): ");
            scanf("%d", &floor);

            if (floor < 1 || floor > 2)
            {
                printf("Invalid floor number.\n");
                continue;
            }

            printf("Enter patient ID: ");
            scanf("%d", &patientID);

            if (patientID <= 0)
            {
                printf("Invalid patient ID.\n");
                continue;
            }

            int found = 0;

            for (j = 0; j < 3; j++)
            {
                for (k = 0; k < 2; k++)
                {
                    if (beds[floor - 1][j][k] == 0)
                    {
                        beds[floor - 1][j][k] = patientID;
                        printf("Patient %d admitted to Floor %d, Ward %d, Bed %d.\n",
                               patientID, floor, j + 1, k + 1);
                        found = 1;
                        break;
                    }
                }

                if (found == 1)
                {
                    break;
                }
            }

            if (found == 0)
            {
                printf("Floor %d is full.\n", floor);
            }
        }
        else if (choice == 2)
        {
            printf("Enter patient ID to discharge: ");
            scanf("%d", &patientID);

            int found = 0;

            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 3; j++)
                {
                    for (k = 0; k < 2; k++)
                    {
                        if (beds[i][j][k] == patientID)
                        {
                            beds[i][j][k] = 0;
                            printf("Patient %d discharged successfully.\n", patientID);
                            found = 1;
                            break;
                        }
                    }

                    if (found == 1)
                    {
                        break;
                    }
                }

                if (found == 1)
                {
                    break;
                }
            }

            if (found == 0)
            {
                printf("Patient ID %d not found.\n", patientID);
            }
        }
        else if (choice == 3)
        {
            printf("\n===== OCCUPANCY REPORT =====\n");

            for (i = 0; i < 2; i++)
            {
                floorOccupied[i] = 0;
            }

            maxOccupied = -1;

            for (i = 0; i < 2; i++)
            {
                printf("\nFloor %d:\n", i + 1);

                for (j = 0; j < 3; j++)
                {
                    occupied = 0;
                    vacant = 0;

                    for (k = 0; k < 2; k++)
                    {
                        if (beds[i][j][k] == 0)
                        {
                            vacant++;
                        }
                        else
                        {
                            occupied++;
                        }
                    }

                    printf("Ward %d: Occupied = %d, Vacant = %d\n",
                           j + 1, occupied, vacant);

                    wardOccupied = occupied;

                    if (wardOccupied > maxOccupied)
                    {
                        maxOccupied = wardOccupied;
                        highestFloor = i;
                        highestWardNumber = j;
                    }

                    floorOccupied[i] = floorOccupied[i] + occupied;
                }

                percentage = (floorOccupied[i] / 6.0) * 100;

                printf("Floor %d Occupancy: %.1f%%\n",
                       i + 1, percentage);

                if (percentage > 80.0)
                {
                    printf("WARNING: Floor %d is more than 80%% full.\n",
                           i + 1);
                }
            }

            printf("\nWard with highest occupancy: Floor %d, Ward %d (%d beds occupied)\n",
                   highestFloor + 1, highestWardNumber + 1, maxOccupied);
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
