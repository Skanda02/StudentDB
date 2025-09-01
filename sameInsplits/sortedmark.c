#include "Student.h"

void displaySortedByMarks()
{
    if(std_count == 0)
    {
        printf("No student found\n");
        return;
    }

    // Temporary array to hold copy
    struct studentinfo temp[50];
    for(int i=0; i<std_count; i++)
    {
        temp[i] = s[i];
    }

    // Selection sort on temp[] by marks
    for(int i=0; i<std_count-1; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<std_count; j++)
        {
            if(temp[j].marks < temp[min_idx].marks)
                min_idx = j;
        }
        if(min_idx != i)
        {
            struct studentinfo t = temp[i];
            temp[i] = temp[min_idx];
            temp[min_idx] = t;
        }
    }

    // Display sorted list
    printf("RollNo | Name                     | Marks\n");
    printf("-----------------------------------------\n");
    for(int i=0; i<std_count; i++)
    {
        printf("%-6d | %-24s | %.2f\n", temp[i].rollno, temp[i].name, temp[i].marks);
    }
}