#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_STUDENTS 5
#define YEAR 2023
#define TMHMA 86

/* Ορισμός πινάκων */
int ArithmosMitroou[NUM_OF_STUDENTS];      /* ΑΜ  Φοιτητών*/
float GraptesErgasies[NUM_OF_STUDENTS][4]; /* Βαθμοί Γραπτών Εργασιών */
float AthroismaGE[NUM_OF_STUDENTS];        /* Αθροισμα Βαθμών Γραπτών Εργασιών */
int PlithosGE[NUM_OF_STUDENTS];            /* Πλήθος Γραπτών Εργασιών που παραδόθηκαν*/
int DikaiomaSymetoxis[NUM_OF_STUDENTS] = {0};    /* Δικαίωμα Συμμετοχής στις Γραπτές Εξετάσεις (0 - 1) */
float GraptesExetasis[NUM_OF_STUDENTS][2] = {0}; /* Βαθμοί Γραπτών Τελικών (στήλη 0) & Επαναληπτικών (στήλη 1) Εξετάσεων */
float TelikosVathmos[NUM_OF_STUDENTS] = {0};     /* Τελικός Βαθμός Μαθήματος */

/* Ορισμός συναρτήσεων */
void input_data();  /* Είσοδος ΑΜ Φοιτητών και Βαθμών Γραπτών Εργασιών */
void exams();       /* Υπολογισμός Αθροίσματος & Πλήθους Γραπτών Εργασιών, και Δικαιώματος Συμμετοχής στις Εξετάσεις */
void input_grade(); /* Είσοδος Βαθμών Γραπτών Τελικών & Επαναληπτικών Εξετάσεων */
void final_grade(); /* Υπολογισμός Τελικού Βαθμόυ */
void print_data();  /* Εκτύπωση Συνολικού Βαθμολόγιου */

int main()
{
    system("chcp 1253>nul");
    input_data(); 
    exams();      
	print_data(); 
    input_grade();
    final_grade(); 
    print_data();  
    return 0; 
}

/* Είσοδος ΑΜ Φοιτητών και Βαθμών Γραπτών Εργασιών */
void input_data()
{
    int i,j;
    for(i=0; i < NUM_OF_STUDENTS-1; i++){
        do{//Ελεγχος για τα ΑΜ Φοιτητών
            printf("A.M. %dου φοιτητή: ",i+1);
            scanf("%d",&ArithmosMitroou[i]);
            if(ArithmosMitroou[i] > 9999){
                printf("Λάθος Τιμή!\n");
            }
        }while(ArithmosMitroou[i] > 9999);

        for(j=0; j < 4; j++){
            do{//Έλεγχος Βαθμών Φοιτητών
                printf("Βαθμός %d Εργασίας (0-10 ή -1 για μη υποβολή):",j+1);
                scanf("%f",&GraptesErgasies[i][j]);
                if(GraptesErgasies[i][j] < 0.0 || GraptesErgasies[i][j] > 10.0){
                    if(GraptesErgasies[i][j] == -1){
                        break;
                    }else{
                        printf("Λάθος εισαγωγή βαθμού\n");
                    }
                }
            }while(GraptesErgasies[i][j] < 0.0 || GraptesErgasies[i][j] > 10.0);
        }
    }
}

/* Υπολογισμός Αθροίσματος & Πλήθους ΓΕ, και Δικαιώματος Συμμετοχής στις Εξετάσεις */
void exams()
{
    int i,j;
    for(i=0; i < NUM_OF_STUDENTS-1; i++){
        for(j = 0; j < 4; j++){
            if(GraptesErgasies[i][j] != -1){
                AthroismaGE[i] += GraptesErgasies[i][j];//Υπολογισμός Αθροίσματος γραπτών εργασιών
                PlithosGE[i] += 1;//Υπολογισμός πλήθους γραπτών εργασιών
            }
        }
        if (AthroismaGE[i] >= 20 && PlithosGE[i] >= 3 ){//Δικαιώματος Συμμετοχής
            DikaiomaSymetoxis[i] = 1;
        }else{
            DikaiomaSymetoxis[i] = 0;
        }
    }
}

/* Είσοδος Βαθμών Γραπτών Τελικών & Επαναληπτικών Εξετάσεων */
void input_grade()
{
    int i;
    for(i = 0; i < NUM_OF_STUDENTS -1; i++){
        if(DikaiomaSymetoxis[i] == 1){//Αν ο φοιτητής εχει το δικαιωμα συμμετοχης στις τελικες
            do{
                printf("Εισαγωγή βαθμού τελικών εξετάσεων (0-10) για τον φοιτητή με ΑΜ %d: ",ArithmosMitroou[i]);
                scanf("%f",&GraptesExetasis[i][0]);
                if(GraptesExetasis[i][0] < 0.0 || GraptesExetasis[i][0] > 10.0){
                    printf("Λάθος τιμή!\n");
                }
            }while(GraptesExetasis[i][0] < 0.0 || GraptesExetasis[i][0] > 10.0);
            printf("\n");
        }
    }
    for(i = 0; i < NUM_OF_STUDENTS -1; i++){
        if(DikaiomaSymetoxis[i] == 1 && GraptesExetasis[i][0] < 5.0){//Αν ο φοιτητής εχει το δικαιωμα συμμετοχης στις επαναληπτικες
            do{
                printf("Εισαγωγή βαθμού Επαναληπτικών εξετάσεων (0-10) για τον φοιτητή με ΑΜ %d: ",ArithmosMitroou[i]);
                scanf("%f",&GraptesExetasis[i][1]);
                if(GraptesExetasis[i][1] < 0.0 || GraptesExetasis[i][1] > 10.0){
                    printf("Λάθος τιμή!\n");
                }
            }while(GraptesExetasis[i][1] < 0.0 || GraptesExetasis[i][1] > 10.0);
            printf("\n");   
        }
    }

}

/* Υπολογισμός Τελικού Βαθμόυ */
void final_grade()
{
    int i;
    for(i = 0; i < NUM_OF_STUDENTS - 1; i++){
        if(DikaiomaSymetoxis[i] == 1 && GraptesExetasis[i][0] >= 5.00){//Αν εχει δικαιωμα συμμετοχής ΚΑΙ εργραψε μεγαλυτερο ισο του 5 στις τελικες
            TelikosVathmos[i] = 0.30*(AthroismaGE[i]/4) + (0.70*GraptesExetasis[i][0]);
        }else if(DikaiomaSymetoxis[i] == 1 && GraptesExetasis[i][0] < 5.00){//Αν εχει δικαιωμα συμμετοχής ΚΑΙ εργραψε μικτρότερο του 5 στις τελικες
            if(GraptesExetasis[i][1] >= 5.00){//Αν εργραψε μεγαλυτερο ισο του 5 στις επαναληπτικες
                TelikosVathmos[i] = 0.30*(AthroismaGE[i]/4) + (0.70*GraptesExetasis[i][1]);   
            }         
        }
        
    }
}

/* Εκτύπωση Συνολικού Βαθμολόγιου (με κενό για τις τιμές 0 στις στήλες ΔΣΕ, Τελική, Επαναλ, Βαθμός) */
void print_data()
{
    printf("-----  ΒΑΘΜΟΛΟΓΙΟ (ΠΛΗ10 - Ακ.Ετος %d-%d - Τμήμα: ΗΛΕ%d)  -----\n",YEAR,YEAR+1,TMHMA);
    printf("\n");
    printf(" ΑΜ | ΓΕ1 | ΓΕ2 | ΓΕ3 | ΓΕ4 | ΔΣΕ | Τελική | Επαναλ | Βαθμός |");
    int i,j;
    for(i=0; i < NUM_OF_STUDENTS-1; i++){
        printf(" %d | %f | %f | %f | %f | %d ", ArithmosMitroou[i],GraptesErgasies[i][0],GraptesErgasies[i][1],GraptesErgasies[i][2],GraptesErgasies[i][3],DikaiomaSymetoxis[i]);
        if(GraptesErgasies[i][0] == 0){//Εκτυπωνει κενο αν υπαρχει 0 ή εκτυπωνει τον αριθμο
            printf("|     ");
        }else{
            printf("| %f ",GraptesErgasies[i][0]);
        }
        if(GraptesErgasies[i][1] == 0){
            printf("|     ");
        }else{
            printf("| %f ",GraptesErgasies[i][1]);
        }
        if(TelikosVathmos[i] == 0){
            printf("|     |");
        }else{
            printf("| %f |",TelikosVathmos[i]);
        }
        printf("\n");
    }

}


