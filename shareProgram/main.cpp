#include <stdbool.h>
#include <stdio.h>
#include "appt.h"
#include "calendar.h"
#include "day.h"
#include "time.h"

//Function Prototype
int getChoice();

int main()
{
  Calendar calendar;
  create(&calendar);
  readFile(&calendar);

  int menuSelection = getChoice();
  while(menuSelection != 0)
    {
      if(menuSelection == 1)
        {
	  dateSearch(&calendar); 
      	  menuSelection = getChoice();
	}
      else //menuSelection = 2
        { 
	  subjectSearch(&calendar);
	  menuSelection = getChoice();
	}
    }    
  //When menu selection = 0
  destroy(&calendar);
}

int getChoice()
{
  printf("Calendar Menu\n");
  printf("0. Done\n");
  printf("1. Search for date.\n");
  printf("2. Search for subject.\n");
	
  int result = -1;

  while((result > 2) || (result < 0))
  {
    scanf("%d", &result);
    char buffer[5];
    fgets(buffer, 5, stdin);
  }	       
	
  printf("Your choice >> %d\n", result);

  return result;
}
