#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll;
    char name[30];
    char dept[20];
    float marks;
};

int main() {
    struct Student s;
    FILE *fp;
    int choice, roll, found;

    while (1) {
        printf("\n--- STUDENT RECORD SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            fp = fopen("student.dat", "ab");
            if (fp == NULL) return 1;
            printf("Enter roll, name, dept, marks: ");
            scanf("%d %29s %19s %f",
                  &s.roll, s.name, s.dept, &s.marks);
            fwrite(&s, sizeof(s), 1, fp);
            fclose(fp);
            printf("Record Added!\n");
        }
        else if (choice == 2) {
            fp = fopen("student.dat", "rb");
            if (fp == NULL) continue;
            while (fread(&s, sizeof(s), 1, fp) == 1)
                printf("%d %s %s %.2f\n",
                       s.roll, s.name, s.dept, s.marks);
            fclose(fp);
        }
        else if (choice == 3) {
            printf("Enter roll number: ");
            scanf("%d", &roll);
            fp = fopen("student.dat", "rb");
            if (fp == NULL) continue;
            found = 0;
            while (fread(&s, sizeof(s), 1, fp) == 1)
                if (s.roll == roll) {
                    printf("%d %s %s %.2f\n",
                           s.roll, s.name, s.dept, s.marks);
                    found = 1;
                }
            if (!found) printf("Student not found\n");
            fclose(fp);
        }
        else if (choice == 4) break;
    }
    return 0;
}