/*
 ***********************************************
 * Name          : build_calendar.h
 * Author        : Sadie Freisthler
 * Version       : 1.0
 * Date          : 4/29/23
 * Last modified : 4/29/23
 * Description   : Functions to build calendar.
 ***********************************************
*/

#ifndef _BUILD_CALENDAR_H_
#define _BUILD_CALENDAR_H_


/**
 * Takes in an integer 1-12
 * Returns: Corresponding month name
*/
char *monthName(int m);

/**
 * Takes in an integer 0-6
 * Returns: Corresponding day of the week
*/
char *dayName(int d);

/**
 * Takes in integer 1-12 for month and integer for year
 * Returns: number of days in given month in given year
*/
int daysInMonth(int monthNum, int year);

/**
 * Takes in integers for date, month, and year
 * Returns: corresponding integer for day of the week
*/
int dayOfWeek(int d, int m, int y);

/**
 * Takes in integers for the moth and year
 * Prints out formatted calendar for that month/year
*/
void printMonth(int m, int y);

/**
 * Takes in integer for year
 * Prints out full calendar for that year
*/
void printCal(int y);


#endif
