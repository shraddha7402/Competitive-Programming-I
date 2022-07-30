/*input:2

14

3

3

4

8

100

4

12

15

25

40*/
#include <stdlib.h>
#include <stdio.h>

int main(void) {
  int cases, days, parties;
  int hartal[100];
  int lost, lost_working_day;
  int c, i, j;
 
  scanf("%d", &cases); // Input the number of testing cases.
 
  for (c=0; c<cases; c++) {
  scanf("%d", &days); // Input the number of days to be simulated.
  scanf("%d", &parties); // Input the number of parties to be simulated.
 
  for (i=0; i<parties; i++) scanf("%d", &hartal[i]); // Input the average hartals of all parties.
 
  lost_working_day = 0; // Initial the lost working days to 0.
  for (i=1; i<=days; i++) { // Check all days to be simulated.
    if (i%7!=6 && i%7!=0) { // Don't check Friday and Saturday.
      lost = 0; // Assume this day is not lost.
      for (j=0; j<parties; j++) lost = lost || (i%hartal[j]==0); // If this day is a hartal for any party, it is lost.
      lost_working_day = lost_working_day + lost; // Update the lost working days.
  }
}
printf("%d\n", lost_working_day); // Output the number of lost working days.
  }
  return 0;
}