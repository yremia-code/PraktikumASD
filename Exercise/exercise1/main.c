#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int d, m, y;
} Date;

typedef struct {
    char name[60];
    double avarageScore;
    Date dob;
} Student;

typedef struct class {
    Student stud[30];
    int numStud;
}Class;

int main()
{
    Class mccs170;
    Date someday;
    mccs170.numStud = 12;
    char *month[12] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    strcpy(mccs170.stud[0].name, "Peter");
    mccs170.stud[0].avarageScore = 88;
    someday.d = 1;
    someday.m = 1;
    someday.y = 1980;
    mccs170.stud[0].dob = someday;

    printf("Name            : %s\n", mccs170.stud[0].name);
    printf("Avarage score   : %.2lf\n", mccs170.stud[0].avarageScore);
    printf("Date of birth   : %d-%s-%d\n\n", mccs170.stud[0].dob.d, month[mccs170.stud[0].dob.m-1], mccs170.stud[0].dob.y);

    strcpy(mccs170.stud[1].name, "Tommy");
    mccs170.stud[1].avarageScore = 91;
    someday.d = 2;
    someday.m = 4;
    someday.y = 1980;
    mccs170.stud[1].dob = someday;

    printf("Name            : %s\n", mccs170.stud[1].name);
    printf("Avarage score   : %.2lf\n", mccs170.stud[1].avarageScore);
    printf("Date of birth   : %d-%s-%d\n\n", mccs170.stud[1].dob.d, month[mccs170.stud[1].dob.m-1], mccs170.stud[1].dob.y);

    return 0;
}
