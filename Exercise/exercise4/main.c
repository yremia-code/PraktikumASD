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

struct Class {
    Student stud[30];
    int numStud;
};

void scandate(Date *aday1, Date *aday2) {
    printf("Masukkan tanggal hari 1 (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &aday1->d, &aday1->m, &aday1->y);

    printf("Masukkan tanggal hari 2 (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &aday2->d, &aday2->m, &aday2->y);
}

int sameDay(Date day1, Date day2) {
    return (day1.y == day2.y && day1.m == day2.m && day1.d == day2.d);
}

int main() {
    Date day1;
    Date day2;

    scandate(&day1, &day2);

    if (sameDay(day1, day2)) {
        printf("It is the same day\n");
    } else {
        printf("It is not the same day\n");
    }
    
    return 0;
}