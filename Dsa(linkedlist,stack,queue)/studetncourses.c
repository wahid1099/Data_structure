#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a subject
struct Subject
{
    char name[50];
    float mark;
    struct Subject *next;
};

// Define a structure for a student
struct Student
{
    char name[50];
    int rollNumber;
    struct Subject *subjects; // Linked list of subjects
    struct Student *next;
};

// Function to add a subject and mark for the student
void addSubject(struct Student *student, const char *subjectName, float subjectMark)
{
    struct Subject *newSubject = (struct Subject *)malloc(sizeof(struct Subject));
    if (newSubject == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    // here we are copying the subject as we cannot directly assign it
    strncpy(newSubject->name, subjectName, sizeof(newSubject->name));
    newSubject->mark = subjectMark;
    newSubject->next = student->subjects;
    student->subjects = newSubject;
}

// Function to display all students and their subjects
void displayStudents(struct Student *head)
{
    struct Student *currentStudent = head;
    while (currentStudent != NULL)
    {
        printf("Name: %s\n", currentStudent->name);
        printf("Roll Number: %d\n", currentStudent->rollNumber);
        printf("Subjects and Marks:\n");

        struct Subject *currentSubject = currentStudent->subjects;
        while (currentSubject != NULL)
        {
            printf("  %s: %.2f\n", currentSubject->name, currentSubject->mark);
            currentSubject = currentSubject->next;
        }

        printf("\n");
        currentStudent = currentStudent->next;
    }
}

int main()
{
    // Create students and add subjects and marks
    struct Student student1 = {"John", 101, NULL, NULL};
    addSubject(&student1, "Math", 90);
    addSubject(&student1, "Science", 85);
    addSubject(&student1, "History", 78);
    addSubject(&student1, "English", 92);
    addSubject(&student1, "Art", 88);

    struct Student student2 = {"Alice", 102, NULL, NULL};
    addSubject(&student2, "Math", 88);
    addSubject(&student2, "Science", 92);
    addSubject(&student2, "History", 76);
    addSubject(&student2, "English", 95);
    addSubject(&student2, "Art", 90);

    // Create a linked list of students and add students
    struct Student *studentList = NULL;
    student1.next = studentList;
    studentList = &student1;
    student2.next = studentList;
    studentList = &student2;

    // Display the linked list of students
    displayStudents(studentList);

    // Free allocated memory for subjects
    struct Student *currentStudent = studentList;
    while (currentStudent != NULL)
    {
        struct Subject *currentSubject = currentStudent->subjects;
        while (currentSubject != NULL)
        {
            struct Subject *temp = currentSubject;
            currentSubject = currentSubject->next;
            free(temp);
        }
        currentStudent = currentStudent->next;
    }

    return 0;
}
