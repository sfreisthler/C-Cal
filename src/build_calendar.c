#include <stdio.h>
#include <stdlib.h>
#include "build_calendar.h"

char* monthName(int m) {
    char *months[12] = {"January","February","March","April","May",
            "June","July","August","September","October","November","December"};
    return months[m-1];
}

char* dayName(int d) {
    char *days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    return days[d];
}

