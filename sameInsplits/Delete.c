#include "Student.h"

void Delete()
{
    // key takes which students roll to delete 
    int key,count=0;
    // in case of no
    if(std_count==0)
    {
        printf("NO student in data base\n");
    }
    else
    {
        int value=0;
        while(!value)
        {
            printf("Enter the RollNo of the student who's data you want to delete \n");
            if(scanf("%d",&key)!=1)
            {
                printf("Enter a valied Rollno\n");
                while(getchar() != '\n');
            }
            else
            {
                value=1;
            }
        }
        for(int i=0;i<std_count;i++)
        {
            if(s[i].rollno==key)
            {
                for(int j=i;j<std_count-1;j++)
                {
                    s[j].rollno=s[j+1].rollno;
                    strcpy(s[j].name,s[j+1].name);
                    s[j].marks=s[j+1].marks;
                }
                count = 1;
                std_count-=1;
                break;
            }
        }
        if(count==0)
        {
            printf("Student not found\n");
        }
    }
    
}