//day.h

#ifndef _DAY_H_
#define _DAY_H_

#include <stdbool.h>
#include "appt.h"
#include "time.h"

typedef struct {
	short day, month, year;
	Appointment appts[8]; //Appointment array full of appointment ptrs
	short apptCount;
} Day;

//Creates a Day with the input of day, month, and year
void create(Day* day, short mm, short dd, short yyyy);

//Returns true if the date of the two Days are the same
bool equal(Day* day1, Day* day2);

//Returns true if day1 < day2
bool lessThan(Day* day1, Day* day2); 

//Dynamically allocates an Appointment
void read(Day* day);

//Prints Appointments in appts
void print(Day* day);

void subjectSearch(Day* day);

void destroy(Day* day);

#endif

