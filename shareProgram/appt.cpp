#include "appts.h"
#include <string.h>

void read(Appointment* appt)
{
  char *ptr = strtok(NULL, ",");
  appt->subject = malloc(strlen(ptr) +1);
  strcpy(appt->subject, ptr);

}

bool lessThan(Appointment* appt1, Appointment* appt2)
{
  return true;
}
