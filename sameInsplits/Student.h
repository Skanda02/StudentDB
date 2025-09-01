#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentinfo {
    int rollno;
    float marks;
    char name[50];
};

extern struct studentinfo s[50];  // only declaration
extern int std_count;             // only declaration

// Function prototypes
void addstudent();
void display();
void search();
void edit();
void Delete();
void displaySortedByMarks();
void loadFromFile();
void saveToFile();

#endif
