#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "build_calendar.h"

void welcome() {
    printf("\n1. Find Day\n");
    printf("2. Print Month\n");
    printf("3. Print Year\n");
    printf("4. EXIT\n");
    printf("ENTER OPTION: ");
}

void printLocalTime() {
    time_t rawtime;
    struct tm *tm;

    time(&rawtime);
    tm = localtime(&rawtime);
    char *day = dayName(tm->tm_wday);
    int date = tm->tm_mday;
    char *month = monthName(tm->tm_mon+1);
    int year = tm->tm_year + 1900;
    printf("\nCurrent Date: %s, %s %d, %d\n",day,month,date,year);
    printMonth(tm->tm_mon+1, year);
}

int main() {
    bool running = true;
    
    printLocalTime();

    while (running) {
	welcome();
	int option, month, year;
	scanf("%d",&option);

	switch(option) {
	    case 1:
		printf("Day");
		break;
	    case 2:
		printf("Enter month/year (MM YYYY): ");
		scanf("%d %d",&month, &year);
		printMonth(month,year);
		break;
	    case 3:
		printf("Enter year (YYYY): ");
		scanf("%d", &year);
		printCal(year);
		break;
	    case 4:
		running = false;
		break;
	    default: 
		printf("Unknown option\n");
		break;
	}

    }
    return EXIT_SUCCESS;
}
