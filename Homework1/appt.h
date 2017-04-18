#pragma once
#include "time.h"

typedef struct Appointment
{
	Time startTime;
	Time endTime;
	char *subject;
	char *location;
}
Appointment;

void read(char *apptStr, Appointment *appt);
bool lessThan(Appointment *apptPtr1, Appointment *apptPtr2);
void destroy(Appointment *apptPtr);
void print(Appointment *apptPtr);
void destroy(Appointment *appt);
