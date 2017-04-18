#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "day.h"
#include "appt.h"

Day *create(char *dayStr)
{
	Day *dayPtr = NULL;
	char *dd, *mm, *yy;
	short d, m, y;
	dd = strtok(dayStr, "/");
	mm = strtok(NULL, "/");
	yy = strtok(NULL, "/");
	d = atoi(dd);
	m = atoi(mm);
	y = atoi(yy);
	//if (d > 31 || m > 12)
	//	return NULL;

	dayPtr = (Day *)malloc(sizeof(Day));
	dayPtr->day = d;
	dayPtr->month = m;
	dayPtr->year = y;
	dayPtr->apptCount = 0;

	return dayPtr;
}

void readAppt(Appointment *apptPtr, Day *dayPtr)
{
	short count = dayPtr->apptCount;
	Appointment *aPtr = NULL;
	Appointment *tempPtr = NULL;
	bool les = false;
	short loc = 0;
	short gap = 0;
	short cur = count;
	if (count == 0)
	{	
		count++;
		dayPtr->appts[0] = *apptPtr;
		dayPtr->apptCount = count;
		return;
	}

	aPtr = dayPtr->appts;
	while (lessThan(aPtr, apptPtr) && loc < cur)
	{
		aPtr++;
		loc++;
	}

	gap = cur - loc;
	while (gap > 0)
	{
		tempPtr = &dayPtr->appts[cur - 1];
		dayPtr->appts[cur] = *tempPtr;
		cur = cur - 1;
		gap = cur - loc;
	}

	dayPtr->appts[loc] = *apptPtr;
	count++;
	dayPtr->apptCount = count;
}

Day *read(char *dayStr, Day *dayPtr)
{
	Appointment *appt = (Appointment *)malloc(sizeof(Appointment));
	read(dayStr, appt);
	readAppt(appt, dayPtr);
	return dayPtr;
}

bool equal(Day *day1, Day *day2)
{
	bool eq = false;
	if (day1->day == day2->day && day1->month == day2->month && day1->year == day2->year)
		eq = true;

	return eq;
}

void print(Day *datePtr)
{
	short acnt = datePtr->apptCount;
	Appointment *appts = datePtr->appts;
	printf("Start End     Subject    Location\n");
	for (int i = 0; i < acnt; i++)
	{
		print(appts);
		printf("\n");
		appts++;
	}
	printf("\n");
}

void subjectSearch(char *subject, Day *datePtr)
{
	int acnt = datePtr->apptCount;
	Appointment *appt = datePtr->appts;
	char *subj, *re;
	for (int j = 0; j < acnt; j++)
	{
		subj = appt->subject;
		re = strstr(subj, subject);
		if (re != NULL)
		{
			printf("%d/%d/%d  ", datePtr->month, datePtr->day, datePtr->year);
			print(appt);
		}
		appt++;
	}
}

void destroy(Day *dayPtr)
{
	int acnt = dayPtr->apptCount;
	Appointment *appt = dayPtr->appts;
	for (int i = 0; i < acnt; i++)
	{
		destroy(appt);
		//free(appt);
		appt++;
	}
}



