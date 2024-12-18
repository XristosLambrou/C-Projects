#include <stdio.h>

int main(){
	system("chcp 1253");/*Εντολή για ορθή εμφάνιση ελληνικών χαρακτήρων στο παράθυρο εξοδου*/
	
	float temp[9];
	float maxtemp, avg,sum, t;
	int position,i, SumOverTemp;
	
	/*Υποερωτημα 1*/
	for (i=0;i<=9;i++){
		do{
			printf("Give temperatures\n");
			scanf("%f",&t);
		}while(t<20 || t>50);
		temp[i] = t;
	}
	
	/*Υποερωτημα 2*/
	sum = 0.0;
	for(i=0;i<=9;i++){
		sum = sum + temp[i];
	}
	avg = sum/10;
	printf("The average temperature of the citys is: %f",avg);
	printf("\n");
	
	/*Υποερωτημα 3*/
	SumOverTemp = 0;
	for (i=0;i<=9;i++){
		if (temp[i] > 40.0){
			SumOverTemp = SumOverTemp + 1;
		}
	}
	printf("The number of cities  with a temperature over 40*C is: %d", SumOverTemp);
	printf("\n");
	
	/*Υποερωτημα 4*/
	maxtemp = temp[0];
	position = 1;
	for(i=0;i<=9;i++){
		if(temp[i] > maxtemp){
			maxtemp = temp[i];
			position = i + 1;
		}
	}
	printf("Maximum temperature: %f  City number: %d", maxtemp,position);
	
	
	printf("\n");
	printf("Program end\n");
	system("PAUSE");
}