#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendar.h"
#include "day.h"
#include "appt.h"
#include "time.h"

void create(Calendar* cal)
{
  cal->days = (Day*) malloc(sizeof(Day) * 30);
  cal->count = 0;
  cal->size = 30;
}

void readFile(Calendar* cal)
{
  FILE* fp = fopen("appts.csv", "r");
  int index = 0;
  char fileLine[80];
  Day dayTemp;
  while(fgets(fileLine, 80, fp))
  {
    if(index == 0)
    {
      index++;
      continue;
    }
    char *ptr = strtok(fileLine, "/");
    int month = atoi(ptr);
    ptr = strtok(NULL, "/");
    int day = atoi(ptr);
    ptr = strtok(NULL, ",");
    int year = atoi(ptr);
    create(&dayTemp, month, day, year);
    bool dayCreated = false;
    for(int i = 0; i <= cal->count; i++)
    {
      if(cal->count == 0) //If there is nothing in the array
      {
	cal->days[i] = dayTemp;
	read(&cal->days[i]);
	dayCreated = true;
	cal->count++;
	break;
      }
      if(equal(&dayTemp, &cal->days[i]))
      {
	read(&cal->days[i]);
	dayCreated = true;
      }
    }
    if(dayCreated == false)
    {
      if(cal->count >= cal->size)
        resize(cal);
      for(int i = cal->count; i >= 0; i--)
      {
	if(lessThan(&dayTemp, &cal->days[i - 1]))
          cal->days[i] = cal->days[i - 1];
	else //when dayTemp is greater than the element in cal->days
	{
          cal->days[i] = dayTemp;
	  read(&cal->days[i]);
          break;
	}
      }
      cal->count++;	
    }
  
  fclose(fp);
  }
}

void resize(Calendar* cal)
{
  Day* newDays = (Day*)malloc(sizeof(Day)* (cal->size * 2));
  for(int i = 0; i < cal->count; i++)
  {
    newDays[i] = cal->days[i];
  }
  free(cal->days);
  cal->days = newDays;
}

void dateSearch(Calendar* cal)
{
  char input[15];
  bool result = false;
  while(result == false)
  {
    printf("Please enter the month, day, and year (mm/dd/yyyy)\n");
    fgets(input, 15, stdin); 
    char *ptr = strtok(input, "/");
    int month = atoi(ptr);
    ptr = strtok(NULL, "/");
    int day = atoi(ptr);
    ptr = strtok(NULL, "\n");
    int year = atoi(ptr);
    if(getDate(month, day, year))
    {
      Day targetDay;
      create(&targetDay, month, day, year);
      result = true;
      for(int i = 0; i < cal->count; i++)
      {
        if(equal(&cal->days[i], &targetDay))
        print(&cal->days[i]);  
      }
    }
  }
}


bool getDate(int month, int day, int year)
{
  if((day <= 31) && (day > 0)
    && (month <= 12) && (month > 0)
    && (year <= 2017) && (year > 2000))
    {
      return true;
    }
  else
  {
    printf("%d/%d/%d is not a valid date.\n", month, day, year);
    printf("Please try again.\n");
    return false;
  }
}

void subjectSearch(Calendar* cal)
{
}

void destroy(Calendar* cal)
{
}
