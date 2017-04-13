//appt.h

#ifndef _APPT_H_
#define _APPT_H_
#include "time.h"

typedef struct {
	Time startTime, endTime;
	char* subject;
	char* location;
} Appointment;

void read(Appointment* appt);

//Does lessThan have startTimes as input parameters or appointment pnters?
bool lessThan(Appointment* appt1, Appointment* appt2);

#endif
