#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d, m, y;
} Date;

int dayofweek(Date aday) {
    int d = aday.d;
    int m = aday.m;
    int y = aday.y;
    
    // Adjust month and year for January and February
    if (m < 3) {
        m += 12;
        y -= 1;
    }
    
    int c = y / 100; // Century
    y = y % 100;     // Year of the century

    // Zeller's Congruence formula
    return (d + (13 * (m + 1)) / 5 + y + (y / 4) + (c / 4) - 2 * c) % 7;
}

int main() {
    Date today;
    char days[7][4] = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"}; // Adjusted to match Zeller's output

    printf("Masukkan tanggal (dd-mm-yyyy): "); // Input format
    scanf("%d-%d-%d", &today.d, &today.m, &today.y);

    int daynow = dayofweek(today);
    printf("Hari pada tanggal %02d-%02d-%04d adalah hari %s\n", today.d, today.m, today.y, days[daynow]);

    return 0;
}