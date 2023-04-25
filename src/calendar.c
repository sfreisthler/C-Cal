#include <stdio.h>
#include <stdlib.h>

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

void printCal(int y) {
    printf("\n\n    %d\n\n",y);
    for (int i = 1; i <= 12; i++) {
	printf("\n-----%s-----\n",monthName(i));
	int num_days;
	num_days = daysInMonth(i,y);
	int current_date = 1;
	int first_day;
	first_day = dayOfWeek(1,i,y);
        int k = 0;
	// Print any leading white space
        while (k < first_day) {
            printf("     ");
	    k++;

        }
	while (current_date <= num_days) {
	    int n;
            n = 1;
            if (current_date > 9) {
                n = 2;
            }
	    if (k > 6) {
		k = 0;
		printf("\n");
		printf("%*s", 3-n,"");
		printf("%d",current_date);
		printf("%*s", 3-n,"");
		k++;
		current_date ++;
	    } else {
		printf("%*s", 3-n,"");
                printf("%d",current_date);
                printf("%*s", 3-n,"");
		k++;
		current_date++;
	    }
	}


	printf("\n");

    }
}


int main() {
    // User input for year
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);    
    printCal(year);

}
