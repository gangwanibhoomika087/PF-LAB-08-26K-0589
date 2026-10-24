#include <stdio.h>

int main()
{
    int marks[4][3];
    int total[4] = {0};
    float average[4];
    int highest[3] = {0};
    int lowest[3] = {100, 100, 100};
    float subjectAverage[3];
    char grade[4];
    char subjects[3][20] = {"Programming", "Calculus", "Physics"};

    int i, j;
    int topStudent = 0;
    int worstSubject = 0;

    for (i = 0; i < 4; i++)
    {
        printf("\nEnter marks for Student %d:\n", i + 1);

        for (j = 0; j < 3; j++)
        {
            do
            {
                printf("Enter %s marks: ", subjects[j]);
                scanf("%d", &marks[i][j]);

                if (marks[i][j] < 0 || marks[i][j] > 100)
                {
                    printf("Invalid marks! Enter marks from 0 to 100.\n");
                }

            } while (marks[i][j] < 0 || marks[i][j] > 100);

            total[i] = total[i] + marks[i][j];

            if (marks[i][j] > highest[j])
            {
                highest[j] = marks[i][j];
            }

            if (marks[i][j] < lowest[j])
            {
                lowest[j] = marks[i][j];
            }
        }

        average[i] = total[i] / 3.0;

        if (i == 0 || average[i] > average[topStudent])
        {
            topStudent = i;
        }

        if (average[i] >= 80)
            grade[i] = 'A';
        else if (average[i] >= 65)
            grade[i] = 'B';
        else if (average[i] >= 50)
            grade[i] = 'C';
        else
            grade[i] = 'F';
    }

    for (j = 0; j < 3; j++)
    {
        int subjectTotal = 0;

        for (i = 0; i < 4; i++)
        {
            subjectTotal = subjectTotal + marks[i][j];
        }

        subjectAverage[j] = subjectTotal / 4.0;
    }

    for (j = 1; j < 3; j++)
    {
        if (subjectAverage[j] < subjectAverage[worstSubject])
        {
            worstSubject = j;
        }
    }

    printf("\n================ STUDENT RESULT REPORT ================\n");

    printf("%-10s", "Student");

    for (j = 0; j < 3; j++)
        printf("%-14s", subjects[j]);

    printf("%-10s %-10s %-8s\n", "Total", "Average", "Grade");

    for (i = 0; i < 4; i++)
    {
        printf("%-10d", i + 1);

        for (j = 0; j < 3; j++)
            printf("%-14d", marks[i][j]);

        printf("%-10d %-10.2f %-8c\n",
               total[i], average[i], grade[i]);
    }

    printf("\n================ SUBJECT ANALYSIS ================\n");

    printf("%-15s %-12s %-12s %-15s\n",
           "Subject", "Highest", "Lowest", "Class Average");

    for (j = 0; j < 3; j++)
    {
        printf("%-15s %-12d %-12d %-15.2f\n",
               subjects[j], highest[j], lowest[j],
               subjectAverage[j]);
    }

    printf("\nTop Student: Student %d (Average: %.2f)\n",
           topStudent + 1, average[topStudent]);

    printf("Worst Subject: %s (Class Average: %.2f)\n",
           subjects[worstSubject], subjectAverage[worstSubject]);

    return 0;
}
