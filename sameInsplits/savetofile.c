#include "Student.h"

void saveToFile()
{
    FILE *fp = fopen("students.txt", "w");  // open file in write mode

    if (fp == NULL)
    {
        printf("Error opening file for saving.\n");
        return;
    }

    for (int i = 0; i < std_count; i++)
    {
        // Use tabs for separation to preserve spaces in names
        fprintf(fp, "%d\t%s\t%.2f\n", s[i].rollno, s[i].name, s[i].marks);
    }

    fclose(fp);  // always close file after writing
    printf("Student data saved to 'students.txt' successfully.\n");
}