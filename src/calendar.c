#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

char* monthName(int m) {
    char *months[12] = {"January","February","March","April","May",
	    "June","July","August","September","October","November","December"};
    return months[m-1];
}

void printMonth(int m, int y) {
    char *month = monthName(m);
    int len = strlen(month), num_days=daysInMonth(m,y), current_date=1,
	first_day = dayOfWeek(1,m,y),counter=0;
    int half = (35-len)/2;
    // Month header spacing
    if (len % 2 == 0) {
	for (int i = 0; i < half; i++) {
	    printf("-");
	}
	printf("%s",month);
	for (int i = 0; i < half+1; i++) {
	    printf("-");
	}
    } else {
	for (int i = 0; i < half; i++) {
            printf("-");
        }
        printf("%s",month); 
        for (int i = 0; i < half; i++) {
            printf("-");
        }
    }
    // Days of the week heading
    printf("\n SUN  MON  TUE  WED  THU  FRI  SAT \n");
    // Print any leading white space
        while (counter < first_day) {
            printf("     ");
	    counter++;
        }
        while (current_date <= num_days) {
            if (counter > 6) {
                counter = 0;
                printf("\n");
                if (current_date > 9) {
                     printf("%*s", 1, "");
                     printf("%d",current_date);
                     printf("%*s", 2,"");
                } else {
                     printf("%*s", 2, "");
                     printf("%d",current_date);
                     printf("%*s", 2,"");
                }
                counter++;
                current_date ++;
            } else {
                if (current_date > 9) {
                     printf("%*s", 1, "");
                     printf("%d",current_date);
                     printf("%*s", 2,"");
                } else {
                     printf("%*s", 2, "");
                     printf("%d",current_date);
                     printf("%*s", 2,"");
                }
                counter++;
                current_date++;
            }
	}
	printf("\n");
}

void printCal(int y) {
    printf("\n\nYear: %d\n\n",y);
    for (int i = 1; i <= 12; i++) {
	printMonth(i,y);
    }
}


int main() {
    // User input for year
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);    
    printCal(year);

}
