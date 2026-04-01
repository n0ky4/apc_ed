#include <stdio.h>

int main(void) {
    char* m[12];
    int n;

    m[0] = "January";
    m[1] = "February";
    m[2] = "March";
    m[3] = "April";
    m[4] = "May";
    m[5] = "June";
    m[6] = "July";
    m[7] = "August";
    m[8] = "September";
    m[9] = "October";
    m[10] = "November";
    m[11] = "December";

    scanf("%d", &n);
    n--;

    if (n >= 0 && n <= 12) printf("%s\n", m[n]);

    return 0;
}
