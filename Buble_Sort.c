#include <stdio.h>


#define n 7
int main(){
	
	int i,k,temp,p[n],s[n]; 
	
	/*Υποερωτημα i*/
	for(i=0; i<=n; i++){
		printf("Give the number for the data array in position:%d ", i+1);
		scanf("%d",&p[i]);
		printf("Give the number for the order array in position: %d ", i+1);
		scanf("%d",&s[i]);
	}
	
	/*Υποερωτημα ii*/
	for(i=0; i<=n-1; i++){
		for(k=0; k<=n-i; i++){
			if(p[s[k]] > p[s[k+1]]){
				temp = p[s[k]];
				p[s[k]] = p[s[k+1]];
				p[s[k+1]] = temp;
			}
		}
	}
	/*Υποερωτημα iii*/
	printf("The sorted array P is:");
	for(i=0; i<=n; i++){
		printf("%d ",p[i]);
	}
	
	
	
	printf("\n");
	printf("Τέλος Προγράμματος\n");
	system("PAUSE");
}