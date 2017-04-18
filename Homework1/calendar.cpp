#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"
#include "day.h"
#include "appt.h"

void create(Calendar *caPtr)
{
	int size = 30, count = 0;
	caPtr->size = size;
	caPtr->count = count;
	caPtr->days = (struct Day*)malloc(caPtr->size * sizeof(Day));
	for (int i = count; i < size; i++)
	{
		caPtr->days[i].day = 0;
		caPtr->days[i].month = 0;
		caPtr->days[i].year = 0;
	}
}

void resize(Calendar *caPtr)
{
	int size = caPtr->size;
	int count = caPtr->count;
	Day *tempDays = caPtr->days;
	size = 2 * size;
	caPtr->days = (struct Day*)malloc(size * sizeof(Day));
	caPtr->size = size;
	memcpy(caPtr->days, tempDays, count * sizeof(Day));
	for (int i = count; i < size; i++)
	{
		caPtr->days[i].day = 0;
		caPtr->days[i].month = 0;
		caPtr->days[i].year = 0;
	}
	free(tempDays);
}

Day *daySearch(Day *dayPtr, Calendar *caPtr)
{
	int index = 0, cnt = caPtr->count;
	bool bDay = false;
	Day *search = caPtr->days;
	while (index < cnt)
	{
		bDay = equal(dayPtr, search);
		if (bDay == true)
		{
			return search;
		}
		search++;
		index++;
	}

	return search;
}

void readFile(char *filename, Calendar *caPtr)
{
	FILE *file = fopen(filename, "r");
	char buff[1024], temp[1024], *token;
	//string val = "";
	Day *dayTemp = NULL, *dayPtr = NULL;
	Appointment *apptPtr = NULL;
	bool bDay;
	int count = caPtr->count;
	while (fgets(buff, sizeof(buff), (FILE*)file) != NULL)
	{
		if (buff[0] == '\n')
			continue;
		if (caPtr->count == caPtr->size)
			resize(caPtr);
		strcpy(temp, buff);
		token = strtok(temp, ",");
		dayPtr = create(temp);
		dayTemp = daySearch(dayPtr, caPtr);
		// if day is not in calendar yet
		if (dayTemp->day == 0 && dayTemp->month == 0)
		{
			dayPtr = read(buff, dayPtr);
			caPtr->days[count] = *dayPtr;
			count++;
			caPtr->count = count;
		}
		else
		{
			dayPtr = dayTemp;
			dayTemp = read(buff, dayPtr);
		}
	}

	fclose(file);
}

void dateSearch(char *dateStr, Calendar *caPtr)
{
	Day *datePtr = create(dateStr);
	datePtr = daySearch(datePtr, caPtr);
	print(datePtr);
}

void subjectSearch(char *subject, Calendar *caPtr)
{
	Day *datePtr = caPtr->days;
	Appointment *appt;
	char *subj;
	int count = caPtr->count;
	int acnt = 0;
	printf("Date       Start End     Subject    Location\n");
	for (int i = 0; i < count; i++)
	{
		subjectSearch(subject, datePtr);
		datePtr++;
	}
	printf("\n");
}

void destroy(Calendar *caPtr)
{
	int count = caPtr->count;
	Day *dayPtr = caPtr->days;
	for (int i = 0; i < count; i++)
	{
		destroy(dayPtr);
		//free(dayPtr);
		dayPtr++;
	}

	free(caPtr);
}



