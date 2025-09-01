#include "Student.h"

void loadFromFile()
{
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("No saved file found.\n");
        return;
    }

    std_count = 0;  // Clear previous data

    char line[100];
    while (fgets(line, sizeof(line), fp))
    {
        // Try to parse using tab-separated format
        if (sscanf(line, "%d\t%[^\t]\t%f", &s[std_count].rollno, s[std_count].name, &s[std_count].marks) == 3)
        {
            std_count++;
            if (std_count >= 50)
            {
                printf("Warning: Max student limit reached while loading.\n");
                break;
            }
        }
        else
        {
            printf("Invalid line in file: %s", line);  // helpful for debugging
        }
    }

    fclose(fp);
    printf("Data loaded successfully from 'students.txt'.\n");
}
