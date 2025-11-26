#include<stdio.h>
#include<string.h>

char candidates[5][20]={
        "Pranav Mukherji",
        "Siddhart Anand",
        "Karanvir Rawal",
        "Dinesh Sharma",
        "Hriday Joshi"
    };
int numCandidates=5;
long votedSapIds[100];
int votedCount = 0;

void welcome();
void all_candidates();
int hasvoted(long);
void recordVote(long);

void welcome(){
    printf("===================================================\n");
    printf("-------Welcome To Voting Management System---------");
    printf("\n=================================================\n\n");
    printf("Instructions For Voting Are As Follows : \n\n");
    printf("-->> View all candidates\n");
    printf("-->> Select your candidate by number\n");
    printf("-->> Multiple voters can participate\n");
    printf("-->> Results will be displayed at the end\n");
    printf("\nPress Enter To Continue.....");
    getchar();
}

void all_candidates(){
    int i;
    printf("\nThe List Of All Candidates For College Elections Is As Follows : \n");
    
    for(i = 0; i < numCandidates; i++) {
        printf("%d. %s\n", i + 1, candidates[i]);
    }
}

int hasVoted(long sapId) {
    for (int i = 0; i < votedCount; i++) {
        if (votedSapIds[i] == sapId) {
            return 1;  
        }
    }
    return 0;  
}
void recordVote(long sapId) {
    votedSapIds[votedCount] = sapId;
    votedCount++;
}

void main()
{
    int choice;
    int totalVoters=0;
    char moreVotes;
    int votes[5]={0,0,0,0,0};
    int Sap_Id;
    
    

    welcome();
    all_candidates();

    do {
        printf("------------------------------\n");
        printf("\nVOTER #%d\n", totalVoters + 1);
        printf("------------------------------\n");

        
        for (int i = 0; i < numCandidates; i++) {
            printf("%d. %s\n", i + 1, candidates[i]);
        }

        
        printf("\n\nEnter Your Sap_ID : ");
        scanf("%d",&Sap_Id);
        
        if (Sap_Id >= 590000000 && Sap_Id <= 600000000) {
    
            if (hasVoted(Sap_Id) == 1) {
                printf("You have already voted! Each student can vote only once.\n");
            }
            else {
                printf("You Are A College Student And Eligible For Voting.");
                printf("\nEnter your choice (1-%d): ", numCandidates);
                scanf("%d", &choice);

                if (choice >= 1 && choice <= numCandidates) {
                    votes[choice - 1]++;   
                    totalVoters++;
                    recordVote(Sap_Id);  
                    printf("Vote recorded successfully!\n");
                } 
                else {
                    printf("Invalid choice! Please try again.\n");
                }
            }
        }
        else {
            printf("You Are Not A College Student. Not Eligible For Voting.\n");
        }
        

        

        
        printf("\nDoes another person want to vote? (y/n): ");
        scanf(" %c", &moreVotes);

    } while (moreVotes == 'y' || moreVotes == 'Y');


    printf("\n====================================\n");
    printf("           VOTING RESULTS\n");
    printf("====================================\n");
    printf("Total Voters: %d\n\n", totalVoters);

    for (int i = 0; i < numCandidates; i++) {
        printf("%s got %d votes.\n", candidates[i], votes[i]);
    }

    int winnerIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (votes[i] > votes[winnerIndex]) {
            winnerIndex = i;
        }
    }
    
    int tieCount=0;

    for(int i = 0; i < numCandidates; i++) {
        if(votes[i] == votes[winnerIndex]) {
            tieCount++;
        }
    }
    printf("\n\n||=============================================||\n");
    printf("||          WINNER ANNOUNCEMENT                ||\n");
    printf("||=============================================||\n");

    if(tieCount > 1) {
        printf(" It's a TIE! The following candidates have equal votes:\n\n");
        for(int i = 0; i < numCandidates; i++) {
            if(votes[i] == votes[winnerIndex]) {
                printf("  %s with %d votes\n", candidates[i],votes[winnerIndex]);
            }
        }
    } else if(votes[winnerIndex] == 0) {
        printf(" No votes were cast!\n");
    } else {
        printf(" WINNER: %s\n", candidates[winnerIndex]);
        printf("   Total Votes: %d\n",votes[winnerIndex]);
        printf("\n Congratulations!\n");
    }
    

    printf("\nThank you for using the Voting System!\n");



}