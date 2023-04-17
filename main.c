#include "functions.h"

int main() {
	while(1){
		printf("1. Student panel \n2. Admin Panel \n3. Exit \n Enter your option: ");
		char input;
		scanf(" %c",&input);

		
		switch (input){
			case '1':
				printf("\nOpening the student panel...\n");
				studentPanel();
				break;
			
			case '2': 
				printf("\nOpening the admin panel...\n");
				adminPanel();
				break;
			case '3':
				printf("Exiting...");
				return 0;
			default:
				printf("\nInvalid option\n");
			
		}
	}
	
}
