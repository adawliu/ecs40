#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"

char *getChoice()
{
	char str[BUFSIZ];
	printf("Calendar Menu\n");
	printf("0. Done\n");
	printf("1. Search for date.\n");
	printf("2. Search for subject.\n");
	printf("\n");
	scanf("%s", str);

	return str;
}

int main()
{
	char input[BUFSIZ], *str;
	char filename[] = "C:/Projects/C++/Homework1/calendar.csv";
	Calendar *calendarPtr = (Calendar *)malloc(sizeof(Calendar));
	create(calendarPtr);
	readFile(filename, calendarPtr);

	while (true)
	{
		str = getChoice();
		if (str[0] == '0')
		{
			destroy(calendarPtr);
			exit(0);
		}
		else if (str[0] == '1')
		{
			printf("Please enter the month, day, and year (mm/dd/yyyy)\n");
			scanf("%s", input);
			dateSearch(input, calendarPtr);
		}
		else if (str[0] == '2')
		{
			printf("Please enter the subject\n");
			scanf("%s", input);
			subjectSearch(input, calendarPtr);
		}
		else
		{
			destroy(calendarPtr);
			exit(0);
		}
	}

	return 0;
}
