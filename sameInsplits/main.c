
#include "Student.h"

struct studentinfo s[50];  // actual definition
int std_count = 0;         // actual definition

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
                Delete();
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