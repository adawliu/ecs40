//calendar.h

#ifndef _CALENDAR_H_
#define _CALENDAR_H_
#include "appt.h"
#include "day.h"
#include "time.h"
#include <stdbool.h>

typedef struct {
  Day* days;
  int size;
  int count;
} Calendar;

void create(Calendar* cal);

void readFile(Calendar* cal);

void resize(Calendar* cal);

void dateSearch(Calendar* cal);

bool getDate(int month, int day, int year);

void subjectSearch(Calendar* cal);

void destroy(Calendar* cal);

#endif
