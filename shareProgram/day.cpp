#include <stdio.h>
#include "day.h"

void create(Day* day, short mm, short dd, short yyyy)
{
  day->day = dd;
  day->month = mm;
  day->year = yyyy;
  day->apptCount = 0;
}

bool equal(Day* day1, Day* day2)
{
  if((day1->day == day2->day) && (day1->month == day2->month) 
    && (day1->year == day2->year))
    return true;
  else //Days not equal
    return false;
}

bool lessThan(Day* day1, Day* day2)
{
  if(day1->year > day2->year)
    return false;
  else if (day1->year < day2->year)
    return true;
  else // if Years are equal
  {  
    if(day1->month > day2->month)
      return false;
    else if(day1->month < day2->month)
      return true;
    else // When years and months are equal
    {  
      if(day1->day > day2->day)
        return false;
      else if(day1->day < day2->day)
	return true;
      else //When dates are completely equal
	return false;
    }
  }
}


void read(Day* day)
{
/*
  Appointment* appt = (Appointment*) malloc(sizeof(Appointment));
  read(appt); //what is this trying to read in? an appointment on a given day? How does it know what day bc we're just passing in appt. I think bc of strtok(NULL,...) then it continues to read from the certain line, so it just reads the appt from that line.  From 4.2.5, it seems like we only call read of day.cpp for the correct date.
  
    for (int i = 0; i <= day->apptCount; i++)
    {
      if(day->apptCount == 0)
	day->appts[0] = appt;
      else if(lessThan(appt.startTime, day->appts[day->apptCount - i - 1]))
	day->appts[day->apptCount - i] = day->appts[day->apptCount - i - 1];
      else //when appt is greater than element in day->appts
        day->appts[day->apptCount - i - 1] = appt;
    }
      day->apptCount++; */
}
      

void print(Day* day){

}

void subjectSearch(Day* day){

}

void destroy(Day* day){

}

