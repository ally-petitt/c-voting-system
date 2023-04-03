#include <string.h>
//#include <conio.h>

struct currentValidID {
	int year;
	char branch[6];
	int totalVoters;
};

struct currentValidID currentValidID; // stores Valid ID user parameters

int extractYear(char userID[15])
{
	return 1;
}

int extractRollNo(char userID[15])
{
	return 1;
}

int checkBranchCode(char userID[15])
{
	return 1;
}


int isValid(char userID[15])
{
	int inputedYear=extractYear(userID);
	int inputedRollNo=extractRollNo(userID);

	if (strlen(userID) != 14)
		return 0;
	if (inputedYear!=currentValidID.year || checkBranchCode(userID) != 1 || inputedRollNo>currentValidID.totalVoters)
		return 0;
	
	return 1;
}

void studentPanel()
{
	char userID[15];
	char voteInput;
	while(1)
	{	
		// get user ID from user input
		printf("\n\n To exit press 0");
		printf("\n Enter user ID:");
		scanf("%s", userID);
		
		if(strcmp(userID, "0")==0)
			return;
			
		if (isValid(userID)!=1)
		{
			printf("\nInvalid User ID (Press Enter)");
			getch();
			continue;
		}
		
	}
}
