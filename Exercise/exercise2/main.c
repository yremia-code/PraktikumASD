#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, m, y;
}Date;

void print_date (Date aday) {
    printf("%d / %d / %d \n", aday.d, aday.m, aday.y);
}

void print_date2 (Date aday) {
    char months[12][4] = {"Jan", "Feb", "Mar",
                           "Apr", "May", "Jun",
                           "Jul", "Aug", "Sep", 
                           "Oct", "Nov", "Dec"};
    printf("%d %s %d\n", aday.d, months[aday.m-1], aday.y);
}

int main()
{
    Date today[2];
    today[0].d = 8;
    today[0].m = 3;
    today[0].y = 2002;
    print_date(today[0]);
    today[1].d = 25; 
    today[1].m = 12;
    today[1].y = 2002;
    print_date2(today[1]);
    return 0;
}

