#include "functions.h"

int main() {
	while(1){
		printf("1. Student panel \n2. Admin Panel \n3. Exit \n Enter your option: ");
		char input;
		scanf(" %c",&input);

		
		switch (input){
			case '1':
				printf("\nYou entered 1\n");
				studentPanel();
				break;
			
			case '2': 
				printf("\nYou entered %c\n", input);
				break;
			case '3':
				printf("exiting...");
				return 0;
			default:
				printf("\nInvalid option\n");
			
		}
	}
	
}
