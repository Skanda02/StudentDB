#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
    int rn;
    float marks;
    char name[50];
};


// structure to store the roll number makrs and name of the student
struct studentinfo
{
    int rollno;
    float marks;
    char name[50];

}s[50]; // can store upto 50 records

// Student count set to 0
int std_count=0;

// Functio used to add new student info
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

void delete()
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




int main()
{
    // ch takes a int value for the switch condidtion
    int ch;
    printf("~~~Welcome to the student database ~~~\n");
    printf("Press:\n1. Add student \n2. Display all \n3. Search  \n4. Edit \n5. Delete \n6. Display students sorted by marks\n7. Save to file\n");
    printf("8. lode from file\n9. Exit\n");
    
    while(1)
    {
        printf("Enter your choice :\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                addstudent();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                edit();
                break;
            case 5:
                delete();
                break;
            case 6:
                displaySortedByMarks();
                break;
            case 7:
                saveToFile();
                break;
            case 8:
                loadFromFile();
                break;
            case 9:
                printf("Thank you\n");
                exit(1);
            
            default:
                printf("Wroung choice\n");
                break;
        }
    }
}
