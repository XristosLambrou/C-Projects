#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <math.h>

#define N 5

/*Ορισμός δομής party*/
struct party{
    int PartyNum;
    char PartyName[10];
    int VoteNum;
    float VotesPercent;
    int SeatNum;
};
/*Δήλωση δείκτη στην δομή party*/
struct party* p;
/*Δήλωση πίνακα election_results*/
struct party election_results[N];
/*Δήλωση και αρχικοποίηση της καθολικής μεταβλητής votes_in_total*/
int votes_in_total = 0;
int j;

void vote_update (){
    //int j;
    int votes = 0;//Μεταβλητή στην οποία κρατάμε τους ψήφους που εισαγει ο χρήστης
    for(j = 0; j < N -1; j++){
        printf("Δώσε το πλήθος έγκυρων ψήφων για το κόμμα με κωδικό %d",election_results[j].PartyNum);
        do{
            scanf("%d",&votes);
            if(votes < 0 ){
                printf("Λάθος εισαγωγή! Βάλε ένα θετικό αριθμό");
            }
        }while(votes < 0);
        election_results[j].VoteNum += votes;
        votes_in_total += votes;
        election_results[j].VoteNum = (election_results[j].VoteNum*100)/(votes_in_total);
    }
}

int winning_party(){
    int max = 0;
    for(j=0; j < N - 1; j++){
        if (election_results[j].VoteNum < election_results[j+1].VoteNum){
            max = j;
        }
    }
    return max;
}

void seat_distribution(){
    int PartiesOut, NumofSeats, winner = 0;
    for(j=0; j < N - 1; j++){//Υπολογίζουμε τις ψηφους των κομμάτων που έμειναν εκτος
        if (election_results[j].VotesPercent < 3.0){
            PartiesOut += election_results[j].VoteNum;
        }
    }
    for(j=0; j < N - 1; j++){//Υπολογισμός εδρών για τα κόμματα
        election_results[j].SeatNum = round(250*(election_results[j].VoteNum/votes_in_total - PartiesOut));
        NumofSeats += election_results[j].SeatNum;
    }
    winner = winning_party();
    election_results[winner].SeatNum += 50;
    NumofSeats += election_results[winner].SeatNum;
    if(NumofSeats == 301){//Κοιτάμε αν οι εδρες συνολικα ειναι περισσότερες ή λιγότερες απο 300
       --election_results[winner].SeatNum;  
    }else{
       ++election_results[winner].SeatNum;        
    }
    printf("Τα τελικά ποσοστά και οι έδρες των κομμάτων είναι:\n");
    for(j=0; j < N - 1; j++){
        printf("Κωδικός:%d Ονομασία:%s Ποσοστό:%f έδρες:%d\n",election_results[j].PartyNum,election_results[j].PartyName, election_results[j].VotesPercent,election_results[j].SeatNum);
    }
}


int main() {
    /*Δήλωση μεταβλητών*/
    int i,answer;
    /*Aρχικοποίηση στοιχείων πίνακα election_results */
    for(i = 0; i < N -1; i++){
        election_results[i].PartyNum = 0;
        strcpy(election_results[i].PartyName,"");
        election_results[i].VoteNum = 0;
        election_results[i].VotesPercent = 0.000;
        election_results[i].SeatNum = 0;
    }
    /*Εισαγωγή στοιχείων στον πίνακα*/
    for(i = 0; i < N -1; i++){
        printf("Εισαγωγή στοιχείων για το %d κόμμα\n",i);
        do{
            printf("Δώσε τον κωδικό του κόμματος\n");
            scanf("%d",&election_results[i].PartyNum);
            if(election_results[i].PartyNum < 0){
                printf("Λάθος εισαγωγή!\n");
            }
        }while(election_results[i].PartyNum < 0);
        printf("Δώσε το όνομα του κόμματος\n");
        gets(election_results[i].PartyName);
    }

    do{
        /*Εμφάνιση menu στον χρήστη "Δώσε 1 για να εισαγάγεις τα αποτελέσματα εκλογικού τμήματος ή 2 για να εκτυπώσεις τα τελικά ποσοστά των συμμετεχόντων κομμάτων και την κατανομή των βουλευτικών εδρών.*/
        printf("Δώσε 1 για να εισαγάγεις τα αποτελέσματα εκλογικού τμήματος ή 2 για να εκτυπώσεις τα τελικά ποσοστά των συμμετεχόντων κομμάτων και την κατανομή των βουλευτικών εδρών.");
        scanf("%d",&answer);
        if (answer = 1) {  //where 
            vote_update();
        }else {	
            seat_distribution();
        }
    }while (answer=1);
    return 0;
}
