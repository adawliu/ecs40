#pragma once
typedef struct Time
{
	short hour;
	short minute;
}
Time;

void read(char *timestr, Time *timeObj);
bool lessThan(Time *time1, Time *time2);
void print(Time *timePtr);