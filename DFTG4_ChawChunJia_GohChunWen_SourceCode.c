//latest version 13/9/2023 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)

#define MAX_STUDENTS 3
#define MAX_NAME_LENGTH 30
#define STUDENT_ID_LENGTH 11

// Function declarations
void menu();
void studentMode();
void adminMode();
void enterResult();

// Global declarations
char adminID[20], studentID[MAX_STUDENTS][STUDENT_ID_LENGTH];
char studentName[MAX_STUDENTS][MAX_NAME_LENGTH];
float gpa_sem1[MAX_STUDENTS], gpa_sem2[MAX_STUDENTS], gpa_sem3[MAX_STUDENTS];
float cgpa[MAX_STUDENTS];
float totalCreditHourS1[MAX_STUDENTS], totalCreditHourS2[MAX_STUDENTS], totalCreditHourS3[MAX_STUDENTS];
char courseCodeS1_1[MAX_STUDENTS][10], courseCodeS1_2[MAX_STUDENTS][10];
char courseCodeS2_1[MAX_STUDENTS][10], courseCodeS2_2[MAX_STUDENTS][10];
char courseCodeS3_1[MAX_STUDENTS][10], courseCodeS3_2[MAX_STUDENTS][10];
float creditHoursS1_1[MAX_STUDENTS], creditHoursS1_2[MAX_STUDENTS], creditHoursS2_1[MAX_STUDENTS], creditHoursS2_2[MAX_STUDENTS], creditHoursS3_1[MAX_STUDENTS], creditHoursS3_2[MAX_STUDENTS];
char gradeObtained_S1_1[MAX_STUDENTS][2], gradeObtained_S1_2[MAX_STUDENTS][2];
char gradeObtained_S2_1[MAX_STUDENTS][2], gradeObtained_S2_2[MAX_STUDENTS][2];
char gradeObtained_S3_1[MAX_STUDENTS][2], gradeObtained_S3_2[MAX_STUDENTS][2];
float gradeSEM1_1[MAX_STUDENTS], gradeSEM1_2[MAX_STUDENTS], gradeSEM2_1[MAX_STUDENTS], gradeSEM2_2[MAX_STUDENTS], gradeSEM3_1[MAX_STUDENTS], gradeSEM3_2[MAX_STUDENTS];
float qualityPoint_S1_1[MAX_STUDENTS], qualityPoint_S1_2[MAX_STUDENTS];
float qualityPoint_S2_1[MAX_STUDENTS], qualityPoint_S2_2[MAX_STUDENTS];
float qualityPoint_S3_1[MAX_STUDENTS], qualityPoint_S3_2[MAX_STUDENTS];
float t_QualityPt_S1[MAX_STUDENTS], t_QualityPt_S2[MAX_STUDENTS], t_QualityPt_S3[MAX_STUDENTS];

void main() {
    printf("===================================================================\n");
    printf(" W       W EEEEEEEE L         CCCCCCC  OOOOOO  M       M EEEEEEEE \n");
    printf(" W       W E        L        C        O      O M M   M M E        \n");
    printf(" W   W   W EEEEEE   L        C        O      O M  M M  M EEEEE    \n");    //Welcome page and immediately lead the user to menu()
    printf(" W W W W W E        L        C        O      O M   M   M E        \n");
    printf("  W  W  W  EEEEEEEE LLLLLLLL  CCCCCCC  OOOOOO  M       M EEEEEEEE \n");
    printf("===================================================================\n");

    printf("                          KOLEJ PASAR                               \n");
    menu();
    system("pause");
}

void menu() {
    int selection;
startingPoint:
    printf("\nWelcome To CGPA calculator: \n");    //menu() page for user to select login modes.
    printf("1. Student\n");
    printf("2. Admin\n");
    printf("3. Exit\n");
    printf("Enter your selection: ");
    scanf("%d", &selection);
    rewind(stdin);

    if (selection == 1) {
        printf("\nWelcome to Student Mode\n");
        studentMode();
    }
    else if (selection == 2) {
        printf("\nWelcome to Admin Mode\n");
        adminMode();
    }
    else if (selection == 3) {
        printf("Bye Bye\n\n");
        exit(0);
    }
    else {
        printf("\n\nEnter a valid number\n\n");
        goto startingPoint;
    }

    system("pause");
}

//Student mode where students are allowed to check their score and generate transcript
void studentMode() {  
    int selection = 0, select = 0;
    char studentLoginID[11];

    printf("\nEnter your Student ID: ");
    scanf("%s", studentLoginID);

    int studentIndex = -1; // Initialize to an invalid index

    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (strcmp(studentID[i], studentLoginID) == 0) {
            studentIndex = i;
            break;
        }
    }

    if (studentIndex == -1) {
        printf("\nInvalid Student ID. Please try again.\n");
        menu();
    }
    else {
        printf("\n\nWELCOME %s\n", studentName[studentIndex]);
        printf("Student ID: %s\n", studentID[studentIndex]);
        printf("Your GPA in semester 1 is: %.2f\n", gpa_sem1[studentIndex]);
        printf("Your GPA in semester 2 is: %.2f\n", gpa_sem2[studentIndex]);
        printf("Your GPA in semester 3 is: %.2f\n", gpa_sem3[studentIndex]);
        printf("Your current CGPA is: %.2f\n\n", cgpa[studentIndex]);
    startingPoint:
        printf("Enter 1 to log out\n");
        printf("Enter 2 to Exit\n");
        printf("Enter 3 to GENERATE TRANSCRIPT\n");
        printf("Enter your selection: ");
        scanf("%d", &selection);
    }
    if (selection == 1) {  //this selection go back to main menu a.k.a the login menu.
        menu();
    }
    else if (selection == 2) { //this ends the program
        printf("\nBye Bye\n");
    }
    else if (selection == 3) {  //this is the EXTRA FEATURE where it generates a transcript of the results for the student, the transcript included gpa and cgpa for every single semester, 
                                //then the overall results for the students
        printf("\n==========================================================\n");
        printf("Student Name           : %s\n", studentName[studentIndex]);
        printf("Student ID             : %s\n", studentID[studentIndex]);
        printf("======================\n");
        printf("=     Semester 1     =\n");
        printf("======================\n");
        printf("Course Code            : %s\n", courseCodeS1_1[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS1_1[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S1_1[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS1_1[studentIndex], qualityPoint_S1_1[studentIndex]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Course Code            : %s\n", courseCodeS1_2[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS1_2[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S1_2[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS1_2[studentIndex], qualityPoint_S1_2[studentIndex]);
        printf("Total Quality Point    : %.2f\n", t_QualityPt_S1[studentIndex]);
        printf("Total Credit Hours     : %.2f\n", totalCreditHourS1[studentIndex]);
        printf("GPA Sem 1              : %.2f\n", gpa_sem1[studentIndex]);
        printf("Current CGPA           : %.2f\n\n", gpa_sem1[studentIndex]);
        printf("======================\n");
        printf("=     Semester 2     =\n");
        printf("======================\n");
        printf("Course Code            : %s\n", courseCodeS2_1[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS2_1[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S2_1[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS2_1[studentIndex], qualityPoint_S2_1[studentIndex]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Course Code            : %s\n", courseCodeS2_2[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS2_2[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S2_2[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS2_2[studentIndex], qualityPoint_S2_2[studentIndex]);
        printf("Total Quality Point    : %.2f\n", t_QualityPt_S2[studentIndex]);
        printf("Total Credit Hours     : %.2f\n", totalCreditHourS2[studentIndex]);
        printf("GPA Sem 2              : %.2f\n", gpa_sem2[studentIndex]);
        printf("Current CGPA           : %.2f\n\n", ((gpa_sem1[studentIndex] + gpa_sem2[studentIndex]) / 2));
        printf("======================\n");
        printf("=     Semester 3     =\n");
        printf("======================\n");
        printf("Course Code            : %s\n", courseCodeS3_1[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS3_1[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S3_1[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS3_1[studentIndex], qualityPoint_S3_1[studentIndex]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Course Code            : %s\n", courseCodeS3_2[studentIndex]);
        printf("Credit Hours           : %.2f\n", creditHoursS3_2[studentIndex]);
        printf("Grade                  : %s\n", gradeObtained_S3_2[studentIndex]);
        printf("Quality Point (for %s) : %.2f\n", courseCodeS3_2[studentIndex], qualityPoint_S3_2[studentIndex]);
        printf("Total Quality Point    : %.2f\n", t_QualityPt_S3[studentIndex]);
        printf("Total Credit Hours     : %.2f\n", totalCreditHourS3[studentIndex]);
        printf("GPA Sem 3              : %.2f\n", gpa_sem3[studentIndex]);
        printf("Current CGPA           : %.4f\n\n", cgpa[studentIndex]);
        printf("[1] Return Menu\n");
        scanf("%d", &select);
        if (select == 1) {
            menu();
        }
    }
    else {
        printf("Enter a valid number");
        goto startingPoint;
    }
}

//The Admin Mode allows the Tutors/Lecturers to edit students details - course code, credit hours, grade obtained. And viewing them.
void adminMode() {
    int selection;
    char inputStudentID[30];

    printf("Admin ID: ");
    scanf("%s", adminID);
    rewind(stdin);

startingPoint:
    printf("\nWelcome %s !\n", adminID); //Here prompts the user to select the mode
    printf("1. View Student Details\n"); //The view mode wont work if there isnt any data entered
    printf("2. Edit Student Details\n");
    printf("3. Go Back Menu\n");
    printf("Enter your selection: ");
    scanf("%d", &selection);

    if (selection == 1) {
        printf("Enter student ID: ");
        scanf("%s", inputStudentID);

        int studentIndex = -1; // Initialize to an invalid index

        for (int i = 0; i < MAX_STUDENTS; i++) {
            if (strcmp(studentID[i], inputStudentID) == 0) {
                studentIndex = i;
                break;
            }
        }

        if (studentIndex == -1) {
            printf("\nInvalid Student ID. Please try again.\n");
            goto startingPoint;
        }
        else {
            printf("\n\nStudent Name     : %s\n", studentName[studentIndex]);  //this area display the students results
            printf("Student ID       : %s\n", studentID[studentIndex]);
            printf("GPA in semester 1: %.2f\n", gpa_sem1[studentIndex]);
            printf("GPA in semester 2: %.2f\n", gpa_sem2[studentIndex]);
            printf("GPA in semester 3: %.2f\n", gpa_sem3[studentIndex]);
            printf("CGPA             : %.2f\n\n", cgpa[studentIndex]);
            printf("Enter 1 to log out\n");
            printf("Enter 2 to Exit\n");
            printf("Enter your selection: ");
            scanf("%d", &selection);
        }
        if (selection == 1) {
            menu();
        }
        else if (selection == 2) {
            printf("Bye Bye");
        }
        else {
            printf("Enter a valid number");
            goto startingPoint;
        }
    }
    else if (selection == 2) { //this is the selection that lead the user to enter result menu.
        enterResult();
    }
    else if (selection == 3) { //this logout the staff to menu page
        menu();
    }
    else {
        printf("\nEnter a valid input\n");
        goto startingPoint;
    }
}

void enterResult() { //This is the functions that allows the admin/staff to enter students results
    int selection;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        printf("\n==================================================================================\n");  //this is the students details, student id and name
        printf("Enter Student ID %d: ", i + 1);
        scanf("%s", studentID[i]);
        rewind(stdin);
        printf("Enter student's Name:");
        scanf("%[^\n]", &studentName[i]);
        printf("\n==================================================================================\n");//This area is entering result for SEMESTER 1
        printf("\nSemester 1\n");
        printf("Course code 1:");
        scanf("%s", &courseCodeS1_1[i]);
    reEnterS1_1:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS1_1[i]);
        rewind(stdin);
        if (creditHoursS1_1[i] != 1 && creditHoursS1_1[i] != 2 && creditHoursS1_1[i] != 3 && creditHoursS1_1[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS1_1;
        }
    reEnterG1_1:
        printf("Grade Obtained:");
        scanf("%s", &gradeObtained_S1_1[i]);

        switch (gradeObtained_S1_1[i][0]) { //grade calculation
        case 'A':
            gradeSEM1_1[i] = 4.00;
            break;
        case 'B':
            gradeSEM1_1[i] = 3.00;
            break;
        case 'C':
            gradeSEM1_1[i] = 2.00;
            break;
        case 'F':
            gradeSEM1_1[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n");
            goto reEnterG1_1;
        }

        if (gradeObtained_S1_1[i][1] == '+') {
            gradeSEM1_1[i] += 0.5;
        }
        else if (gradeObtained_S1_1[i][1] == '-') {
            gradeSEM1_1[i] -= 0.25;
        }

        qualityPoint_S1_1[i] = creditHoursS1_1[i] * gradeSEM1_1[i];
        printf("Quality Point for %s: %.2f", courseCodeS1_1[i], qualityPoint_S1_1[i]); //displaying grade

        printf("\n\nCourse code 2:");
        scanf("%s", &courseCodeS1_2[i]); //entering results for course2 in semester 1
        rewind(stdin);
    reEnterS1_2:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS1_2[i]);
        rewind(stdin);
        if (creditHoursS1_2[i] != 1 && creditHoursS1_2[i] != 2 && creditHoursS1_2[i] != 3 && creditHoursS1_2[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS1_2;
        }
        rewind(stdin);
    reEnterG1_2:
        printf("Grade Obtained:"); //displaying grade
        scanf("%s", &gradeObtained_S1_2[i]);
        rewind(stdin);

        switch (gradeObtained_S1_2[i][0]) { //grade calculation
        case 'A':
            gradeSEM1_2[i] = 4.00;
            break;
        case 'B':
            gradeSEM1_2[i] = 3.00;
            break;
        case 'C':
            gradeSEM1_2[i] = 2.00;
            break;
        case 'F':
            gradeSEM1_2[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n");
            goto reEnterG1_2;
        }

        if (gradeObtained_S1_2[i][1] == '+') {
            gradeSEM1_2[i] += 0.5;
        }
        else if (gradeObtained_S1_2[i][1] == '-') {
            gradeSEM1_2[i] -= 0.25;
        }

        qualityPoint_S1_2[i] = creditHoursS1_2[i] * gradeSEM1_2[i];
        printf("Quality Point for %s: %.2f", courseCodeS1_2[i], qualityPoint_S1_2[i]); //displaying quality point

        t_QualityPt_S1[i] = qualityPoint_S1_1[i] + qualityPoint_S1_2[i]; //formula for calculation of quality pooint
        totalCreditHourS1[i] = creditHoursS1_1[i] + creditHoursS1_2[i];
        gpa_sem1[i] = t_QualityPt_S1[i] / totalCreditHourS1[i];

        printf("\nTotal Quality Point For SEM 1 is :%.2f", t_QualityPt_S1[i]);
        printf("\nTotal Credit Hours For SEM 1 is :%.2f", totalCreditHourS1[i]);
        printf("\nGPA for SEM 1 is : %.2f", gpa_sem1[i]);
        printf("\n==================================================================================\n"); //displaying total gpa cgpa and details for semester 1
        printf("\nSemester 2\n");
        printf("Course code 3:");
        scanf("%s", &courseCodeS2_1[i]);//Entering semester 2 results
        rewind(stdin);
    reEnterS2_1:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS2_1[i]);
        rewind(stdin);
        if (creditHoursS2_1[i] != 1 && creditHoursS2_1[i] != 2 && creditHoursS2_1[i] != 3 && creditHoursS2_1[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS2_1;
        }
        rewind(stdin);
    reEnterG2_1:
        printf("Grade Obtained:");
        scanf("%s", &gradeObtained_S2_1[i]);
        rewind(stdin);

        switch (gradeObtained_S2_1[i][0]) { //grade calculation
        case 'A':
            gradeSEM2_1[i] = 4.00;
            break;
        case 'B':
            gradeSEM2_1[i] = 3.00;
            break;
        case 'C':
            gradeSEM2_1[i] = 2.00;
            break;
        case 'F':
            gradeSEM2_1[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n");
            goto reEnterG2_1;
        }

        if (gradeObtained_S2_1[i][1] == '+') {
            gradeSEM2_1[i] += 0.5;
        }
        else if (gradeObtained_S2_1[i][1] == '-') {
            gradeSEM2_1[i] -= 0.25;
        }

        qualityPoint_S2_1[i] = creditHoursS2_1[i] * gradeSEM2_1[i];
        printf("Quality Point for %s: %.2f", courseCodeS2_1[i], qualityPoint_S2_1[i]); //displaying quality point

        printf("\n\nCourse code 4:");
        scanf("%s", &courseCodeS2_2[i]); //semester 2 course 4
        rewind(stdin);
    reEnterS2_2:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS2_2[i]);
        rewind(stdin);
        if (creditHoursS2_2[i] != 1 && creditHoursS2_2[i] != 2 && creditHoursS2_2[i] != 3 && creditHoursS2_2[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS2_2;
        }
    reEnterG2_2:
        printf("Grade Obtained:");
        scanf("%s", &gradeObtained_S2_2[i]); //entering grade obtained
        rewind(stdin);

        switch (gradeObtained_S2_2[i][0]) { //grade calculation
        case 'A':
            gradeSEM2_2[i] = 4.00;
            break;
        case 'B':
            gradeSEM2_2[i] = 3.00;
            break;
        case 'C':
            gradeSEM2_2[i] = 2.00;
            break;
        case 'F':
            gradeSEM2_2[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n");
            goto reEnterG2_2;
        }

        if (gradeObtained_S2_2[i][1] == '+') {
            gradeSEM2_2[i] += 0.5;
        }
        else if (gradeObtained_S2_2[i][1] == '-') {
            gradeSEM2_2[i] -= 0.25;
        }

        qualityPoint_S2_2[i] = creditHoursS2_2[i] * gradeSEM2_2[i];
        printf("Quality Point for %s: %.2f", courseCodeS2_2[i], qualityPoint_S2_2[i]); //calculation of quality point

        t_QualityPt_S2[i] = qualityPoint_S2_1[i] + qualityPoint_S2_2[i];
        totalCreditHourS2[i] = creditHoursS2_1[i] + creditHoursS2_2[i];  //calculation of gpa 
        gpa_sem2[i] = t_QualityPt_S2[i] / totalCreditHourS2[i];

        printf("\nTotal Quality Point For SEM 2 is :%.2f", t_QualityPt_S2[i]);
        printf("\nTotal Credit Hours For SEM 2 is :%.2f", totalCreditHourS2[i]);
        printf("\nGPA for SEM 2 is : %.2f", gpa_sem2[i]);
        printf("\n==================================================================================\n"); //displaying results for 2 semester 
        printf("\nSemester 3\n");
        printf("Course code 5:");
        scanf("%s", &courseCodeS3_1[i]); //entering semester 3 results
        rewind(stdin);
    reEnterS3_1:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS3_1[i]);
        rewind(stdin);
        if (creditHoursS3_1[i] != 1 && creditHoursS3_1[i] != 2 && creditHoursS3_1[i] != 3 && creditHoursS3_1[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS3_1;
        }
    reEnterG3_1:
        printf("Grade Obtained:");
        scanf("%s", &gradeObtained_S3_1[i]); //grade obtained
        rewind(stdin);

        switch (gradeObtained_S3_1[i][0]) { //grade calculation
        case 'A':
            gradeSEM3_1[i] = 4.00;
            break;
        case 'B':
            gradeSEM3_1[i] = 3.00;
            break;
        case 'C':
            gradeSEM3_1[i] = 2.00;
            break;
        case 'F':
            gradeSEM3_1[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n"); //invalid input
            goto reEnterG3_1;
        }

        if (gradeObtained_S3_1[i][1] == '+') {
            gradeSEM3_1[i] += 0.5;
        }
        else if (gradeObtained_S3_1[i][1] == '-') {
            gradeSEM3_1[i] -= 0.25;
        }

        qualityPoint_S3_1[i] = creditHoursS3_1[i] * gradeSEM3_1[i];
        printf("Quality Point for %s: %.2f", courseCodeS3_1[i], qualityPoint_S3_1[i]); //calculation of quality point

        printf("\n\nCourse code 6:");
        scanf("%s", &courseCodeS3_2[i]); //semester 3 course 6 details
        rewind(stdin);
    reEnterS3_2:
        printf("Credit Hours:");
        scanf("%f", &creditHoursS3_2[i]);
        rewind(stdin);
        if (creditHoursS3_2[i] != 1 && creditHoursS3_2[i] != 2 && creditHoursS3_2[i] != 3 && creditHoursS3_2[i] != 4) {
            printf("Invalid value, please enter again\n");
            goto reEnterS3_2;
        }
    reEnterG3_2:
        printf("Grade Obtained:"); //grade obtained
        scanf("%s", &gradeObtained_S3_2[i]);
        rewind(stdin);

        switch (gradeObtained_S3_2[i][0]) { //grade obtained calculation
        case 'A':
            gradeSEM3_2[i] = 4.00;
            break;
        case 'B':
            gradeSEM3_2[i] = 3.00;
            break;
        case 'C':
            gradeSEM3_2[i] = 2.00;
            break;
        case 'F':
            gradeSEM3_2[i] = 0.00;
            break;
        default:
            printf("Invalid Grade, please enter again\n");
            goto reEnterG3_2;
        }

        if (gradeObtained_S3_2[i][1] == '+') {
            gradeSEM3_2[i] += 0.5;
        }
        else if (gradeObtained_S3_2[i][1] == '-') {
            gradeSEM3_2[i] -= 0.25;
        }

        qualityPoint_S3_2[i] = creditHoursS3_2[i] * gradeSEM3_2[i];
        printf("Quality Point for %s: %.2f", courseCodeS3_2[i], qualityPoint_S3_2[i]); //quality point  calculation

        t_QualityPt_S3[i] = qualityPoint_S3_1[i] + qualityPoint_S3_2[i];
        totalCreditHourS3[i] = creditHoursS3_1[i] + creditHoursS3_2[i]; //calculation for gpa 
        gpa_sem3[i] = t_QualityPt_S3[i] / totalCreditHourS3[i];

        printf("\nTotal Quality Point For SEM 3 is :%.2f", t_QualityPt_S3[i]);
        printf("\nTotal Credit Hours For SEM 3 is :%.2f", totalCreditHourS3[i]);
        printf("\nGPA for SEM 3 is : %.2f", gpa_sem3[i]);

        cgpa[i] = (t_QualityPt_S1[i] + t_QualityPt_S2[i] + t_QualityPt_S3[i]) / (totalCreditHourS1[i] + totalCreditHourS2[i] + totalCreditHourS3[i]); 
        printf("\n\nCGPA for %s is : %.2f\n", studentName[i], cgpa[i]); //displaying students results in gpa and cpa for whole year

        printf("\n==================================================================================\n");


        printf("Select 1 to menu\n");
        printf("Select 2 to another student\n\n"); //prompting the admin to return to menu or edit another students details and results
    redoSelection:
        printf("Selection > ");
        scanf("%d", &selection);

        if (selection == 1) {
            menu();
        }
    }

    printf("\nEnter 1 to log out\n");
    printf("Enter 2 to Exit\n");
    printf("Enter your selection: "); //admin mode after entering all students details (max == 3)
    scanf("%d", &selection);

    if (selection == 1) {
        menu();
    }
    else if (selection == 2) {
        printf("Bye Bye");
        return 0;
    }
    else {
        printf("Enter a valid number");
        enterResult();
    }
}
