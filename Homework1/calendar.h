#pragma once
#include "day.h"

typedef struct Calendar
{
	struct Day *days;
	int size;
	int count;
}
Calendar;

void create(Calendar *caPtr);
void readFile(char *filename, Calendar *caPtr);
Day *daySearch(Day *dayPtr, Calendar *caPtr);
void resize(Calendar *caPtr);
void dateSearch(char *dateStr, Calendar *caPtr);
void subjectSearch(char *subject, Calendar *caPtr);
void destroy(Calendar *caPtr);


