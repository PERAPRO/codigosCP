#include<stdio.h>

int main(void){
	short int t;
	scanf("%d",&t);
	for(int T=0;T<t;T++){
		int input;
		scanf("%d",&input);
		int sum = 0;
		for(int n =1; n<input;n++){
			if((input%n) == 0)
				sum = sum + n;
		}
		if(sum < input){
			printf("deficient\n");
		}
		else if (sum > input){
			printf("abundant\n");
		}
		else{
			printf("perfect\n");
		}
		
	}
	return 0;
}