#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct currentValidID {
	int year;
	char branch[6];
	int totalVoters;
};

typedef struct candidate{
	int cid;
	char cname[20];
	int votes;
} CANDIDATE;

struct currentValidID currentValidID; // stores Valid ID user parameters
CANDIDATE candidateArray[20]; //to store information on all candidates
int numberOfCandidates; //Total number of candidates standing for election
char studentVotes[200];  //to store information of votes given by each student

//To extract year from userID -- For example, userID:2018btecs00064 year:2018 
int extractYear(char userID[15])
{
	int year=0;
	int num;
	
	for (int i=0;i<4;i++){
		num = userID[i] - 48;
		year = year + (num * pow(10,3-i));
	}
	
	return year;
}

int checkBranchCode(char userID[15])
{
	char branchCode[6];
	for (int i=0; i<5; i++) {
		branchCode[i] = userID[i+4];
	}
	
	branchCode[5] = '\0';
	
	if (strcmp(branchCode, currentValidID.branch) == 0)
		return 1;
	else
		return 0;
	
}



int extractRollNo(char userID[15])
{
	int rollno=0;
	int num;
	
	for (int i=9; i<14; i++) {
		num = userID[i] - 48;
		rollno = rollno + (num * pow(10, 13-i));
	}
	
	printf("rollno is %d", rollno);
	return rollno;
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

int authenticateAdmin() {
	char username[15], password[6];
	
	printf("\nEnter username: ");
	scanf("%s", username);
	
	if ((strcmp(username, "Admin")) != 0)
		return 0;
	else
	{
		printf("Enter Password: ");
		scanf(" %s", password);
		
		if ((strcmp(password, "admiN")) !=0)
			return 0;
		
		return 1;
		
	}

}



void adminPanel()
{
	while(1){
	
		if (authenticateAdmin() != 1) {
			printf("\nWrong Username or Password\n");
			break;
		}
	
		printf("\n\nLOGGED IN SUCCESSFULLY (Press Enter)");
		getchar();
		getchar();
		
		// TODO: finish
	
	}

}



void studentPanel()
{
	char userID[15];
	int voteInput;
	while(1)
	{	
	
	
		// TODO: remove
		//checkBranchCode("2018btecs00064");
		
		
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
