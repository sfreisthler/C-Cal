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

char* monthName(int monthNum) {
    char *month;
    switch (monthNum) {
	case 1:
	    month = "January";
	    break;
	case 2:
	    month = "February";
	    break;
	case 3:
	    month = "March";
	    break;
	case 4:
	    month = "April";
	    break;
	case 5:
	    month = "May";
	    break;
	case 6:
	    month = "June";
	    break;
	case 7:
	    month = "July";
	    break;
	case 8:
	    month = "August";
	    break;
	case 9:
	    month = "September";
	    break;
	case 10:
	    month = "October";
	    break;
	case 11:
	    month = "November";
	    break;
	case 12:
	    month = "December";
    }
    return month;
}

void printCal(int y) {
    printf("\n\n    %d\n\n",y);
    for (int i = 1; i <= 12; i++) {
	
	printf("%s\n",monthName(i));
	int day = dayOfWeek(1,i,y);
	printf("%d\n", day);
    }
}


int main() {
    // User input for year
    int year;
    printf("Enter a year: ");
    scanf("%d",&year);    
    printCal(year);

}
