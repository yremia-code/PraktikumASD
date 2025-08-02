#include <stdio.h>
#include <string.h>

typedef struct {
    int d, m, y;
} Date;

typedef struct {
    char name[60];
    double averageScore;
    Date dob;
} Student;

typedef struct {
    Student stud[30];
    int numStud;
} Class;

int isYounger(Student stud1, Student stud2) {
    if (stud1.dob.y > stud2.dob.y) {
        return 1; // stud1 is younger
    } else if (stud1.dob.y < stud2.dob.y) {
        return 0; // stud1 is not younger
    } else {
        if (stud1.dob.m > stud2.dob.m) {
            return 1; // stud1 is younger
        } else if (stud1.dob.m < stud2.dob.m) {
            return 0; // stud1 is not younger
        } else {
            if (stud1.dob.d > stud2.dob.d) {
                return 1; // stud1 is younger
            } else {
                return 0; // stud1 is not younger
            }
        }
    }
}

void scanStud(Class *isi, int index) {
    printf("Name                : ");
    scanf("%s", isi->stud[index].name);
    printf("Birth (dd-mm-yy)    : ");
    scanf("%d-%d-%d", &isi->stud[index].dob.d, &isi->stud[index].dob.m, &isi->stud[index].dob.y);
}

int main() {
    Class itc;
    printf("Enter the number of students: ");
    scanf("%d", &itc.numStud); // Input jumlah siswa

    // Loop untuk memasukkan data siswa
    for (int i = 0; i < itc.numStud; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        scanStud(&itc, i); // Menggunakan indeks i untuk setiap siswa
    }

    // Perbandingan usia antara siswa pertama dan kedua
    for (int i = 0; i < itc.numStud; i++) {
        for (int j = i + 1; j < itc.numStud; j++) {
            if (isYounger(itc.stud[i], itc.stud[j])) {
                printf("%s is younger than %s\n", itc.stud[i].name, itc.stud[j].name);
            } else {
                printf("%s is younger than %s\n", itc.stud[j].name, itc.stud[i].name);
            }
        }
    }

    return 0;
}