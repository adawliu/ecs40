#include <iostream>
#include <string.h>
#include <stdlib.h> 
#include "time.h"

void read(char *timestr, Time *timeObj)
{
	char *tm;
	char *m;
	char *sub;
	short hr;
	short min;

	tm = strtok(timestr, " ");
	m = strtok(NULL, " ");
	sub = strtok(tm, ":");
	hr = atoi(sub);
	if (m[0] == 'P' && m[1] == 'M')
		hr = hr + 12;
	sub = strtok(NULL, ":");
	min = atoi(sub);
	timeObj->hour = hr;
	timeObj->minute = min;
	return;
}

bool lessThan(Time *time1, Time *time2)
{
	bool less = false;
	short hr1 = time1->hour;
	short min1 = time1->minute;
	short hr2 = time2->hour;
	short min2 = time2->minute;

	if (hr1 < hr2)
		return true;

	if (hr1 == hr2 && min1 < min2)
		return true;

	return less;
}

void print(Time *timePtr)
{
	short hr = timePtr->hour;
	short min = timePtr->minute;
	if (hr < 10)
	{
		if (min < 10)
			printf("0%d:0%d ", hr, min);
		else
			printf("0%d:%d ", hr, min);
	}
	else
	{
		if (min < 10)
			printf("%d:0%d ", hr, min);
		else
			printf("%d:%d ", hr, min);
	}
}