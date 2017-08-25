#ifndef __CALCULATE_DAYS__
#define __CALCULATE_DAYS__

typedef enum month {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} Month;

int calculateDays(Month, int, int);
int isLeap(int);

#endif
