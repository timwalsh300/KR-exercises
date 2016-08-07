/* Page 112: There is no error checking in day_of_year or
** month_day as shown on page 111. Remedy this defect.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 10

extern int mygetline(char *, int);
int day_of_year_helper(void);
void month_day_helper(char *);

int main(void)
{
	char selection[MAXLINE], output[MAXLINE];

	printf("Choose 1 to get the day of the year from a date.\n");
	printf("Choose 2 to get the date from a day of the year.\n");
	printf("Enter selection: ");
	mygetline(selection, MAXLINE);

	if(strcmp(selection, "1") == 0) {
		printf("The day of the year is number %d\n", day_of_year_helper());
	} else if(strcmp(selection, "2") == 0) {
		month_day_helper(output);
		printf("The date is %s\n", output);
	} else {
		printf("%s is not a valid selection... exiting the program\n", selection);
	}
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isLeapYear(int);

int day_of_year(int, int, int);

int day_of_year_helper(void)
{
	char input[MAXLINE], year_str[5], month_str[3], day_str[3];
	int year_int, month_int, day_int;

	printf("Enter the date as yyyymmdd: ");
	mygetline(input, MAXLINE);
	if (strlen(input) != 8) {
		printf("%s is not a valid date format\n", input);
	}

	strncpy(year_str, input, 4);
	year_str[4] = '\0';
	year_int = atoi(year_str);

	strncpy(month_str, input + 4, 2);
	month_str[2] = '\0';
	month_int = atoi(month_str);

	strncpy(day_str, input + 6, 2);
	day_str[2] = '\0';
	day_int = atoi(day_str);

	if (month_int < 1 || month_int > 12) {
		printf("%s is not a valid input for the month\n", month_str);
		return -1;
	}
	if (day_int < 1 || day_int > daytab[isLeapYear(year_int)][month_int]) {
		printf("%s is not a valid input for the day\n", day_str);
		return -1;
	}

	return day_of_year(year_int, month_int, day_int);
}

void month_day(int, int, int *, int *);

void month_day_helper(char *output)
{
	char num_str[MAXLINE], year_str[MAXLINE], month_str[MAXLINE], day_str[MAXLINE];
	int *day = malloc(sizeof(int));
	int *month = malloc(sizeof(int));
	int valid_days;

	printf("Enter the number day of the year: ");
	mygetline(num_str, MAXLINE);
	printf("Enter the year: ");
	mygetline(year_str, MAXLINE);

	valid_days = isLeapYear(atoi(year_str)) ? 366 : 365;
	if (atoi(num_str) < 1 || atoi(num_str) > valid_days) {
		printf("%s is not a valid numbered day\n", num_str);
		sprintf(output, "ERROR");
		free(day);
		free(month);
		return;
	}
	month_day(atoi(year_str), atoi(num_str), month, day);
	if (*month < 10) {
		sprintf(month_str, "0%d", *month);
	} else {
		sprintf(month_str, "%d", *month);
	}
	if (*day < 10) {
		sprintf(day_str, "0%d", *day);
	} else {
		sprintf(day_str, "%d", *day);
	}
	sprintf(output, "%s%s%s", year_str, month_str, day_str);
	free(day);
	free(month);
}

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = isLeapYear(year);
	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = isLeapYear(year);
	for (i = 1; yearday > daytab[leap][i]; i++) {
		yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}

int isLeapYear(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}
