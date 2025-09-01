#include "Student.h"

void display()
{
    // If no student is present it should give a message
    if(std_count==0)
    {
        printf("No student found\n");
    }
    // to print the info
    else
    {
        printf("~~~ Student info ~~~~\n");
        for(int i=0;i<std_count;i++)
        {
            printf("Student RollNo : %d\n",s[i].rollno);
            printf("Name of the student : %s \n",s[i].name);
            printf("Marks : %f\n",s[i].marks);
            printf("\n");
            printf("----------------------\n");
        }
    }
    
}