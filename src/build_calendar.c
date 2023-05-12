#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

int daysInMonth(int monthNum, int year) {
    int days;

    if (monthNum == 4 || monthNum == 6 || monthNum == 9
                    || monthNum == 11) {
        days = 30;
    } else if (monthNum == 2) {
        if (year % 4 == 0) {
            days = 28;
        } else {
            days = 29;
        }
    } else {
        days = 31;
    }
    return days;
}

int dayOfWeek(int d, int m, int y) {
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

void printDate(int d, bool current) {
    char *color;
    if (current) {
	color = "\033[31m";
    } else {
	color = "\033[0m";
    }
    if (d > 9) {
        printf("%*s", 1, "");
        printf("%s%d\033[0m",color,d);
        printf("%*s", 2,"");
    } else {
        printf("%*s", 2, "");
        printf("%s%d\033[0m",color,d);
        printf("%*s", 2,"");
    }

}

void printMonth(int m, int y) {
    time_t rawtime;
    struct tm *tm;

    time(&rawtime);
    tm = localtime(&rawtime);
    int date_cur = tm->tm_mday;
    int month_cur = tm->tm_mon+1;
    char *month = monthName(m);
    int len = strlen(month), num_days=daysInMonth(m,y), current_date=1,
        first_day = dayOfWeek(1,m,y),counter=0;
    int half = (35-len)/2;
    // Month header spacing
    if (len % 2 == 0) {
        for (int i = 0; i < half; i++) {
            printf("\033[1m\033[46m-");
        }
        printf("%s",month);
        for (int i = 0; i < half+1; i++) {
            printf("-");
        }
	printf("\033[0m");
    } else {
        for (int i = 0; i < half; i++) {
            printf("\033[1m\033[46m-");
        }
        printf("%s",month);
        for (int i = 0; i < half; i++) {
            printf("-");
        }
	printf("\033[0m");
    }
    // Days of the week heading
    printf("\n \033[1mSUN  MON  TUE  WED  THU  FRI  SAT\033[0m\n");
    // Print any leading white space
        while (counter < first_day) {
            printf("     ");
            counter++;
        }
        while (current_date <= num_days) {
	    bool current = false;
	    if (current_date == date_cur && m == month_cur) {
		current = true;
	    }

            if (counter > 6) {
                counter = 0;
                printf("\n");
		printDate(current_date,current);
            } else {
		printDate(current_date,current);
            }
	    counter++;
	    current_date++;
        }
        printf("\n");
}

void printCal(int y) {
    printf("\n\nYear: %d\n\n",y);
    for (int i = 1; i <= 12; i++) {
        printMonth(i,y);
    }
}




