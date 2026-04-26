#include <stdio.h>
#include <stdlib.h>


struct Student {
    int rollNo;
    char name[50];
    float marks;
};

int main() {
    struct Student *students; 
    int n, i;

    printf("Enter number of students: ");
    scanf("%d", &n);


    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

   
    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &(students[i].rollNo));
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); 
        printf("Marks: ");
        scanf("%f", &(students[i].marks));
    }

  
    printf("\n--- Student Information ---\n");
    for (i = 0; i < n; i++) {
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n\n", students[i].marks);
    }

    
	
	free(students);

    return 0;
}

