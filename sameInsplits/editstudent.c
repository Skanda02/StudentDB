#include "Student.h"

void edit()
{
    //count to know if the student with the enterd roll number is present or not
    // key to know who's data to edit
    // roll
    int count=0,key,roll;

    // incase the db has no student 
    if(std_count==0)
    {
        printf("No student found\n");
    }
    else
    {
        int valied=0;
        while(!valied)
        {
            printf("Enter the students rollno who's data you want to edit\n");
            if(scanf("%d",&key)!=1) // cheack if it's a int
            {
                printf("Enter a valied Rollno\n");
                while(getchar()!= '\n');
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
                int duplicate;
                do
                {
                    duplicate=0;
                    int valu=0;
                    while(!valu)
                    {
                        printf("Enter the modified student RollNo :");
                        if(scanf("%d",&roll) !=1)
                        {
                            printf("Enter a valied Rollno:\n");
                            while(getchar()!='\n');
                        }
                        else
                        {
                            valu=1;
                        }
                        
                    }
                    for(int j=0;j<std_count;j++)
                    {
                        if(s[j].rollno==roll && j != i) // To change in the same roll no j != i
                        {
                            // incase if someone enters his own rollNo nothing will happen
                            // but if he/she trys to change the rollno to a allready existing roll it will give this output

                            printf("Student with rollno %d already exist's\n",roll);
                            duplicate=1;
                        }
                    }
                }while (duplicate);
            
                while (getchar() != '\n');  // clear newline before taking name input

                s[i].rollno=roll;
                //while (getchar() != '\n');  // flush the newline left in the buffer
                printf("Enter the modified Name of the student :");
                fgets(s[i].name, sizeof(s[i].name), stdin);
                s[i].name[strcspn(s[i].name, "\n")] = '\0';

                size_t len = strlen(s[i].name);
                if (len > 0 && s[i].name[len - 1] == '\n') 
                {
                    s[i].name[len - 1] = '\0';
                }

                int mark=0;
                while(!mark)
                {
                    printf("Enter the modified Marks : ");
                    if(scanf("%f",&s[i].marks)!=1)
                    {
                        printf("Enter a Valied mark");
                        while(getchar()!='\n');
                    }
                    else
                    {
                        mark=1;
                    }
                }
                
                count = 1;
            }
        }
        if(count==0)
        {
            printf("No student with rollno %d found\n",key);
        }
    
    }
}