#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Preprocessor variables */
#define N_PARTIES 5
#define PARTIES_SEATS 20
#define FIRST_PARTY_SEATS_BONUS 10
#define MINIMUM_PERCENTAGE 5
#define REGISTERED 112524

/* Structures and Types declaration */
struct PARTY{
    char name[20];
    int votes;
    float persentage;
    int seatnum;
};

/* Functions declaration */
int argMax(float[], int);

/* Variables declaration */
/* Λευκά */
int BLANK;
/* /Ακυρα */
int VOID;
/* Συνολικά έγκυρα. Δηλώνουμε τη μεταβλητή float το αποτέλεσμα τις διαίρεσης ψήφοι/total είναι δεκαδικός. */
float VALID;
int SUM;
float FIRST_PARTY;
int POS;
float VOAT_METER;
float remainders[N_PARTIES];         /* Σε αυτό τον πίνακα θα κρατάμε τα υπόλοιπα των συνδυασμών. */
int remaining_seats = PARTIES_SEATS; /* Σε αυτή τη μεταβλητή θα ελέγχουμε πόσες θέσεις παραμένουν μετά την πρώτη κατανομή. */

/* Main function */
int main()
{
    system("chcp 1253>nul");
    struct PARTY parties[N_PARTIES];
    /* 1.1 */
    /* Εισάγετε τα ονόματα των συνδυασμών */
    /* Δεν απαιτείται η χρήση αμυντικού προγραμματισμού. Πρέπει να γίνεται εισαγωγή αλφαριθμητικών. */
    int i;
    for (i=0; i < N_PARTIES; i++ ){
        printf("Εισάγετε το όνομα του %dου συνδιασμού:",i+1);
        scanf("%19s",parties[i].name);
    }


    /* Εισάγετε τα έγκυρα, λευκά, άκυρα.
     * Απαιτείται η χρήση αμυντικού προγραμματισμού για έλεγχο αρνητικών τιμών.
     * Απαιτείται η χρήση αμυντικού προγραμματισμού στο τέλος της εισαγωγής όλων των παραμέτρων.
     */
    do{
        /*Εισαγωγή Λευκά*/
        printf("Από τους 112524 εγγεγραμμένους ψηφοφόρους εισάγετε τον αριθμό των λευκών ψηφοδελτίων");
        do{
            scanf("%d",&BLANK);
            if(BLANK < 0){
                printf("Δώσατε αρνητικό αριθμό λευκών.\n Κάν'τε ξανά την εισαγωγή με θετικό\n");
            }
        }while(BLANK < 0);

        /*Εισαγωγή Άκυρων*/
        printf("Από τους 112524 εγγεγραμμένους ψηφοφόρους εισάγετε τον αριθμό των άκυρων ψηφοδελτίων");
        do{
            scanf("%d",&VOID);
            if(VOID < 0){
                printf("Δώσατε αρνητικό αριθμό λευκών.\n Κάν'τε ξανά την εισαγωγή με θετικό\n");
            }
        }while(VOID < 0);


        /*Εισαγωγή Ψήφων Συνδιασμών*/
        int i;
        //SUM = 0;
        VALID = 0.0;
        for (i=0; i < N_PARTIES; i++){
            printf("Εισάγετε τους ψήφους που έλαβε ο συνδιασμός %s:",parties[i]);
            do{
                scanf("%d",&parties[i].votes);
                if(parties[i].votes < 0){
                    printf("Δώσατε αρνητικό αριθμό ψήφων.\n Κάν'τε ξανά την εισαγωγή με θετικό\n");
                }
            }while(parties[i].votes < 0);
            VALID = VALID + parties[i].votes;/*Άθροισμα έγκυρων ψήφων*/
        }

        if(VALID + VOID + BLANK > REGISTERED ){
            printf("Ο συνολικός αριθμός ψήφων που εισάγατε είναι %d, μεγαλύτερος από τον αριθμό %d των εγγεγραμμένων ψηφοφόρων.\n",SUM , REGISTERED);
            printf("Παρακαλώ επαναλάβετε την εισαγωγή\n");
        }
    }while(VALID + VOID + BLANK > REGISTERED);
    
    /* 1.2 */
    /* Eάν ικανοποιείται η παραπάνω συνθήκη τότε το πρόγραμμα συνεχίζει στον υπολογισμό των ποσοστών κάθε συνδυασμού. */
    /* Υπολογισμός του συνδυασμού με τους περισσότερους ψήφους */
    /* Για λόγους απλότητας θεωρούμε ότι δύο συνδυασμοί δεν έχουν ίδιο αριθμό ψήφων. */
    POS = 0;
    FIRST_PARTY = 0.0;
    for (i=0; i < N_PARTIES; i++){
        parties[i].persentage = parties[i].votes/VALID;
        if (parties[i].persentage > FIRST_PARTY){
            FIRST_PARTY = parties[i].persentage;
            POS = i;
        }
    }

    /* Εάν ο πρώτος συνδυασμός έχει ποσοστό μικρότερο του 43% Εμφανίστε στην οθόνη ότι θα γίνουν επαναληπτικές εκλογές και τερματίστε το πρόγραμμα. */
    if(FIRST_PARTY < 43.0){
        printf("Θα γίνουν επαναληπτικές εκλογές");
        return 0;
    }else{   /* Αλλιώς δώσε στον συνδυασμό με τις περισσότερες ψήφους το BONUS των εδρών */
        printf("Το μέγιστο ποσοστό έχει ο συνδιασμός %c με %f%. Άρα δεν θα γίνει δεύτερος γύρος εκλογών.\n",parties[POS].name,parties[POS].persentage);
        printf("Ο συνδιασμός %c ανακηρύσσεται νικητης και λαμβανει BONUS 10 έδρες",parties[POS].name);
        parties[POS].seatnum = FIRST_PARTY_SEATS_BONUS;
    }

    /* 1.2 */
    /* Πρώτη κατανομή εδρών */
    VOAT_METER = 100 / (PARTIES_SEATS - FIRST_PARTY_SEATS_BONUS);
    printf("Υπολογισμός εδρών πρώτης 1ης κατανομής\n");
    for(i=0; i < N_PARTIES-1; i++){
        if(parties[i].persentage >= MINIMUM_PERCENTAGE){
            parties[i].seatnum += parties[i].persentage / VOAT_METER;
            remainders[i] = fmod(parties[i].persentage, VOAT_METER);
            remaining_seats = remaining_seats - parties[i].seatnum;
            printf("Συνδιασμός %c Έδρες: %d\n",parties[i].name,parties[i].seatnum);
        }else if(parties[i].persentage < MINIMUM_PERCENTAGE){
            parties[i].seatnum = 0;
            printf("Ο συνδιασμός %c δεν διεκδικεί έδρες.\n",parties[i].name);
        }
    }
    /* 1.3 */
    /* Υπολογισμός 2ης κατανομής των υπόλοιπων εδρών. */
    printf("Υπολογισμός εδρών 2ης Κατανομής\n");
    
    while (remaining_seats > 0)
    {
        i = argMax(remainders,N_PARTIES);
        /* Χρήση της συνάρτησης argMax για να βρούμε τη θέση του μεγαλύτερου στοιχείου στον πίνακα με τα υπόλοιπα */
        /*Αφού βρούμε σε ποιόν συνδυασμό αντιστοιχεί το μέγιστο υπόλοιπο, αλλάζουμε την τιμή σε -1 ώστε να μην είναι πλέον μεγαλύτερη. */
        /* Δίνουμε την 1 έδρα στον συνδυασμό με το μεγαλύτερο υπόλοιπο που βρέθηκε από την argMax. */
        /* Αφαιρούμε μια έδρα από το υπόλοιπο των εδρών. */
        remainders[i] = -1;
        parties[i].seatnum += 1;
        remaining_seats -=1;
        printf("Συνδιασμος %c Έδρες 1\n",parties[i].name);
    }

    /* Εμφανίστε στην οθόνη τον αριθμό των έγκυρων, άκυρων, λευκών, αποχής. */
    /* Εμφανίστε το όνομα τις ψήφους, ποσοστά και έδρες κάθε συνδυασμού. */
    printf("Τελικά αποτελέσματα\n");
    printf("Το ποσοστό κάθε συνδιασμού υπολογίζεται στα έγκυρα ψηφοδέλτια\n");
    for(i=0; i<N_PARTIES-1; i++){
        printf("Ο συνδιασμός:%c. Έλαβε:%d ψήφους. Ποσοστό:%f. Έδρες:%d",parties[i].name,parties[i].votes,parties[i].persentage,parties[i].seatnum);
    }
    return 0;
}

/* Η συνάρτηση argMax επιστρέφει την θέση στην οποία βρίσκεται η μέγιστη τιμή του πίνακα array με πλήθος στοιχείων array_length.*/
int argMax(float array[], int array_length)
{
    int i;
    int maxIndex = 0;
    for (i = 0; i < array_length - 1; i++)
    {
        if (array[i + 1] > array[maxIndex])
        {
            maxIndex = i + 1;
        }
    }
    return maxIndex;
}
