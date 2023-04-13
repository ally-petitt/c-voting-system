#include <string.h>
#include <stdio.h>

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


int isBanned(char userID[15])
{
	return 0;
}

int isVoted(char userID[15])
{
	return 0;
}

void saveVote(char userID[15], int voteInput)
{
	return 0;
}


void studentPanel()
{
	char userID[15];
	int voteInput;
	while(1)
	{	
		// get user ID from user input
		printf("\n\n To exit press 0");
		printf("\n Enter user ID: ");
		scanf("%s", userID);
		
		if(strcmp(userID, "0")==0)
			return;
			
		// if (isValid(userID)!=1)
		if (0)
		{
			printf("\nInvalid User ID (Press Enter)");
			getchar();
			getchar();
			continue;
		}
		if (isBanned(userID) != 0)
		{
			printf("\nThis User ID is currently banned...\nContact Admin for the reason...(Press Enter)");
			getchar();
			getchar();
			continue;
		}
		if (isVoted(userID)!=0)
		{
			printf("\nYour PRN entered is already voted (Press Enter)");
			getchar();
			getchar();
			continue;
		}
		
		int numberOfCandidates = 12; //TODO: remove
		printf("\n\nCandidates for election:");
		for (int i=0; i< numberOfCandidates; i++)
		{
			//printf("\n\t%d. %s", i+1, candidate Array[i].cname);
			printf("\n\t%d", i); // TODO: remove
		}
		printf("\n\nEnter Your Vote (Number): ");
		scanf(" %d", &voteInput);
		printf("You voted for candidate number %d", voteInput);
		
		
		if (voteInput < 1 || voteInput > numberOfCandidates)
		{
			printf("\nInvalid Vote\nTry Again (Press Enter)");
			getchar();
			getchar();
			continue;
		}
		
		saveVote(userID, voteInput);
		printf("\n\nThank you for voting! (Press Enter)");
		getchar();
		getchar();
		
	}
};
