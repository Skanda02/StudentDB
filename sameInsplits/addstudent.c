# include "Student.h"

void addstudent()
{
    int no_std,roll;
    printf("Enter the number of students :\n");
    scanf("%d",&no_std); 
    for(int i=0;i<no_std;i++)
    {
        int duplicate; // used to makes sure no 2 students with same rollno is entered
        // do while loop used coz it will be executed ones no matter what
        do
        {
            duplicate=0;
            int valied=0;
            while(!valied) // when the rollno is valied it will come out of the loop
            {
                printf("Enter the student RollNo :");
                if(scanf("%d",&roll) !=1) // %d takes int value if the enterde value is int it wii retuen 1
                {
                    printf("Invalid input. Please enter a valid number.\n"); //handel char 
                    while(getchar() != '\n'); // clear leftover newline
                }
                // when a valid rollno is entered it will set valied to 1
                else
                {
                    valied=1;
                }
            }
            for(int j=0;j<std_count;j++)
            {
                if(s[j].rollno==roll) // checks if the enterd roll no is allready in the db
                {
                    printf("Student with rollno %d already exist's\n",roll);
                    duplicate=1;
                }
            }
        }while (duplicate);

        while (getchar() != '\n');  // clear leftover newline

        // finaly stores the rollno 😂
        s[std_count].rollno=roll;

        printf("Enter the Name of the student :");
        // fgets(source,size,type)
        fgets(s[std_count].name, sizeof(s[std_count].name), stdin);
        s[std_count].name[strcspn(s[std_count].name, "\n")] = '\0';

        float marks;
        while (1)
        {
            printf("Enter marks: ");
            // make sure no char is enterd 
            if (scanf("%f", &marks) == 1) 
            {
                break; // valid input, exit loop
            }  
            else
            {
                printf("Invalid input. Please enter a valid float.\n");
                while (getchar() != '\n'); // flush buffer
            }
        }
        // stores the marks
        s[std_count].marks=marks;

        // Every time a student is added it increses the count of the student
        std_count +=1;
    }
}