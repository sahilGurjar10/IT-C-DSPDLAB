#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float avgMarks;
} Student;

void bubbleSort(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].avgMarks < students[j + 1].avgMarks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    Student students[n];
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
    }

    bubbleSort(students, n);

    printf("\nStudents sorted in descending order by Average Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d | Name: %s | Age: %d | Avg Marks: %.2f\n",
               students[i].id, students[i].name, students[i].age, students[i].avgMarks);
    }

    return 0;
}
