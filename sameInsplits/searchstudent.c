#include "Student.h"

void search()
{
    int key,count=0;
    if(std_count==0)
    {
        printf("No student found\n");
    }
    else
    {
        int valied=0;
        while(!valied)
        {
            printf("Enter a roll number to search\n");
            if(scanf("%d",&key)!=1)
            {
                printf("Enter a valied RollNo:\n");
                while(getchar() != '\n');
            }
            else
            {
                valied=1;
            }
        }
        for(int i=0;i<std_count;i++)
        {
            if(s[i].rollno==key)
            {
                printf("Student RollNo : %d\n",s[i].rollno);
                printf("Name of the student : %s \n",s[i].name);
                printf("Marks : %f\n",s[i].marks);
                count = 1;
            }
        }
        if(count==0)
        {
            printf("Student not found\n");
        }
    }
    
}
