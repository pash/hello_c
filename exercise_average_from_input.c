#include <stdio.h>

char input[1000];
char choice;    // choice for input
float temp;     // temporary storage for numbers entered
int num_count;  // number counter
float total; 
float average;

int main() {
	printf("This program will get the average of numbers you enter.\n");
  printf("Type 'n' to enter a number.\n");
	printf("Type 'q' to quit and get average.\n");

  // initialize variables
	num_count = 0;
	total = 0.0;
	average = 0.0;

// loop until user quits by typing 'q'
while (1) {
  
	// enter number or compute average and quit
	printf("Enter n or q: ");
	fgets(input, sizeof(input), stdin);
	sscanf(input, "%c", &choice);

	switch (choice) {
		case 'n':
			printf("Enter number now: ");
			fgets(input, sizeof(input), stdin);
			sscanf(input, "%f", &temp);
			
			// increases with each number entered
			++num_count; 
			
			// add to total
			total += temp;
			
			// reset
			temp = 0;
			continue;
			
		case 'q':
			break;
			
		default:
			printf("Invalid choice. Choices are 'n' or 'q'.\n");
			continue;
	}
	break;
}
	average = ( total / num_count );
	printf("%d numbers entered. Average is %f.\n", num_count, average);

return 0;
}