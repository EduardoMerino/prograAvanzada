#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "calculate_days.h"

/*Calculate Days
 * given a month and day return the number of days.
 * @param:
 *  currentMonth: Month
 *  monthDay: day of the monthDay
 * @return:
 *  integer number of days.
 */
int calculateDays(Month currentMonth, int monthDay, int year){
  int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int days = monthDay;
  Month i;

  if (isLeap(year)){
    daysPerMonth[FEB] += 1;
  }

  assert(monthDay >= 1 && monthDay <= daysPerMonth[currentMonth]);

  for(i = JAN; i < currentMonth; i++){
    days += daysPerMonth[i];
  }

  return days;
}

/* Is Leap
 * given a year return 1 if year is leap.
 * @param:
 * int year
 * @return:
 * 1 if year is leap, 0 if it isn't.
 */
 int isLeap(int year){
   if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
     return 1;
   } else {
     return 0;
   }
 }
