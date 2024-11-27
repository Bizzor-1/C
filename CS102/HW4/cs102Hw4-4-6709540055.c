#include <stdio.h>
#include <string.h>
int courses_count = 0;
typedef struct {
    char courseCode[10];
    char courseName[50];
    int credits;
} Course;
Course c[10];

int student_count = 0;
typedef struct {
    char studentID[10];
    char name[50];
    Course registeredCourses[10];
    int coursesCount;
} Student;
Student std[100];

void addCourse() {
    char code[10],course_name[50];
    int credit;

    printf("Enter Course Code: ");
    fgets(c[courses_count].courseCode, 10, stdin);
    c[courses_count].courseCode[strcspn(c[courses_count].courseCode, "\n")] = '\0';

    printf("Enter Course Name: ");
    fgets(c[courses_count].courseName, 50, stdin);
    c[courses_count].courseName[strcspn(c[courses_count].courseName, "\n")] = '\0';

    printf("Enter Credits: ");
    scanf("%d", &c[courses_count].credits);

    printf("Course added successfully.\n");
    courses_count++;
}

void addStudent() {
    printf("Enter Student ID: ");
    fgets(std[student_count].studentID, 10, stdin);
    std[student_count].studentID[strcspn(std[student_count].studentID, "\n")] = '\0';
    
    printf("Enter Student Name: ");
    fgets(std[student_count].name, 10, stdin);
    std[student_count].name[strcspn(std[student_count].name, "\n")] = '\0';

    std[student_count].coursesCount = 0;
    printf("Student added successfully.\n");
    student_count++;
}

void registerCourse() {

    char studentID[10], courseCode[10];

    printf("Enter Studdent ID: ");
    fgets(studentID, 10, stdin);
    studentID[strcspn(studentID, "\n")] = '\0';

    int studentIndex = -1,i;
    for (i = 0; i  < student_count; i++) {
        if (strcmp(studentID,std[i].studentID) == 0) {
            studentIndex = i;
        }
    }

    if (studentIndex == -1) {
        printf("Student ID not found.\n");
        return;
    }

    printf("Enter Course Code to Register: ");
    fgets(courseCode, 10, stdin);
    courseCode[strcspn(courseCode, "\n")] = '\0';

    int courseIndex = -1;
    for (i = 0; i < courses_count; i++) {
        if (strcmp(courseCode,c[i].courseCode) == 0) {
            courseIndex = i;
        }        
    }
    
    if (courseIndex == -1) {
        printf("Course Code not found.\n");
        return;
    }

    for (int i = 0; i < std[studentIndex].coursesCount; i++) {
        if (strcmp(std[studentIndex].registeredCourses[i].courseCode, courseCode) == 0) {
            printf("Course already registered by the student.\n");
            return;
        }
    }

    std[studentIndex].registeredCourses[std[studentIndex].coursesCount++] = c[courseIndex];
    printf("Course registered successfully.\n");

}

void displayStudentCourses() {
    int i,j;
    char id[10];
    
    printf("Enter Student ID: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = '\0';

    for (i = 0; i < student_count; i++) {
        if (strcmp(id, std[i].studentID) == 0) {
            printf("Courses registered by %s\n", std[i].name);
            printf("%-15s %-30s %-10s\n", "Course Code", "Course Name", "Credits");
            for (j = 0; j < std[i].coursesCount; j++) {
                printf("%-15s %-30s %-10d\n", std[i].registeredCourses[j].courseCode, std[i].registeredCourses[j].courseName, std[i].registeredCourses[j].credits);
            }
            return;
        }
    }

    printf("Student ID not found.\n");
}

void saveData() {
    int i,j;
    FILE *filePtr = fopen("registration_data.txt", "w");
    fprintf(filePtr, "%d\n", courses_count);
    for (i = 0; i < courses_count; i++) {
        fprintf(filePtr, "%s\n%s\n%d\n", c[i].courseCode, c[i].courseName,  c[i].credits);
    }
    
    fprintf(filePtr, "%d\n", student_count);
    for (i = 0; i < student_count; i++) {
        fprintf(filePtr, "%s\n%s\n%d\n", std[i].studentID, std[i].name, std[i].coursesCount);

        for (j = 0; j < std[i].coursesCount; j++) {
            fprintf(filePtr, "%s\n", std[i].registeredCourses[j].courseCode);
        }
    }

    fclose(filePtr);
    printf("Data saved successfully.\n");
    
}

void loadData() {
    int i,j,k;
    FILE *filePtr = fopen("registration_data.txt", "r");
    fscanf(filePtr, "%d\n", &courses_count);
    for (i = 0; i < courses_count; i++) {
        fgets(c[i].courseCode, 10, filePtr);
        c[i].courseCode[strcspn(c[i].courseCode, "\n")] = '\0';
        fgets(c[i].courseName, 50, filePtr);
        c[i].courseName[strcspn(c[i].courseName, "\n")] = '\0';
        fscanf(filePtr, "%d\n", &c[i].credits);
    }
    
    fscanf(filePtr, "%d\n", &student_count);
    for (i = 0; i < student_count; i++) {
        fgets(std[i].studentID, 10, filePtr);
        std[i].studentID[strcspn(std[i].studentID, "\n")] = '\0';
        fgets(std[i].name, 50, filePtr);
        std[i].name[strcspn(std[i].name, "\n")] = '\0';
        fscanf(filePtr, "%d\n", &std[i].coursesCount);

        for (j = 0; j < std[i].coursesCount; j++) {
            fgets(std[i].registeredCourses[j].courseCode, 10, filePtr);
            std[i].registeredCourses[j].courseCode[strcspn(std[i].registeredCourses[j].courseCode, "\n")] = '\0';

            for (k = 0; k < courses_count; k++) {
                if (strcmp(std[i].registeredCourses[j].courseCode, c[k].courseCode) == 0) {
                    strcpy(std[i].registeredCourses[j].courseName, c[k].courseName);
                    std[i].registeredCourses[j].credits = c[k].credits;
                    break; 
                }
            }
        }
    }

    fclose(filePtr);
    printf("Data loaded successfully.\n");
    
}

int main () {
    int input;
    do {
        printf("===== Course Registration System =====\n");
        printf("1. Add New Course\n");
        printf("2. Add New Student\n");
        printf("3. Register Course for Student\n");
        printf("4. Display Student's Registered Courses\n");
        printf("5. Save Data\n");
        printf("6. Load Data\n");
        printf("7. Exit\n");
        printf("Select an option (1-7): ");
        scanf("%d", &input);
        getchar();
        switch (input) {
            case (1) :addCourse(); printf("\n"); break;
            case (2) :addStudent(); printf("\n"); break;
            case (3) :registerCourse(); printf("\n"); break;
            case (4) :displayStudentCourses(); printf("\n"); break;
            case (5) :saveData(); printf("\n"); break;
            case (6) :loadData(); printf("\n"); break;
            case (7) :
                saveData();
                printf("Exiting the program. Goodbye!\n");
                break;
        }
    } while (input != 7);
    
    return 0;
}