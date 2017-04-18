#pragma once
#include "appt.h"

typedef struct Day
{
	short day;
	short month;
	short year;
	short apptCount;
	struct Appointment appts[8];
}
Day;

Day *create(char *dayStr);
Day *read(char *dayStr, Day *dayPtr);
bool equal(Day *day1, Day *day2);
void print(Day *datePtr);
void subjectSearch(char *subject, Day *datePtr);
void destroy(Day *dayPtr);



