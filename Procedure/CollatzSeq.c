#include <stdio.h>

void collatzSequence(int n){
	if(n <=0){
		printf("Input has to be a positive integer!");
		return;	
	}
	printf("Collatz sequence for %d:\n ",n);
	printf("%d ",n);
	while(n!=1){
		printf("=>");
		if(n%2 == 0){
			n = n/2;
		}
		else{
			n = n*3 + 1;
		}
		printf(" %d ",n);
	}
	printf("\n");
	
}

void main(){
	int n;
	printf("Enter an integer: ");
	scanf("%d",&n);
	collatzSequence(n);
	
	
}
