#include <iostream>
#include <stdlib.h> 
#include <string.h>
#include "time.h"
#include "appt.h"

void read(char *apptStr, Appointment *appt)
{
	char *dt;
	char *subStr;
	char *startStr;
	char *endStr;
	char *locStr;
	Time *startPtr = (Time *)malloc(sizeof(Time));
	Time *endPtr = (Time *)malloc(sizeof(Time));

	dt = strtok(apptStr, ",");
	subStr = strtok(NULL, ",");
	startStr = strtok(NULL, ",");
	endStr = strtok(NULL, ",");
	locStr = strtok(NULL, ",");
	read(startStr, startPtr);
	read(endStr, endPtr);

	appt->startTime = *startPtr;
	appt->endTime = *endPtr;
	appt->subject = strdup(subStr);
	appt->location = strdup(locStr);
}

bool lessThan(Appointment *apptPtr1, Appointment *apptPtr2)
{
	bool less = false;
	Time startTime1 = apptPtr1->startTime;
	Time startTime2 = apptPtr2->startTime;
	less = lessThan(&startTime1, &startTime2);

	return less;
}

void print(Appointment *apptPtr)
{
	Time start = apptPtr->startTime;
	Time end = apptPtr->endTime;
	char *sub = apptPtr->subject;
	char *loc = apptPtr->location;
	print(&start);
	print(&end);
	printf("  %s", apptPtr->subject);
	printf("     %s", apptPtr->location);
}

void destroy(Appointment *appt)
{
	//free(&appt->startTime);
	//free(&appt->endTime);
}

