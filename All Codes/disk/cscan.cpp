#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	printf("Enter no of requests: ");
	scanf("%d",&n);
	int req[n];
	for(int i=0;i< n;i++){
		scanf("%d",&req[i]);
	}
	//sorting 
	
	for(int i=0;i< n;i++){
		for(int j=i+1;j<n;j++){
			if(req[i] > req[j]){
				int temp = req[i];
				req[i] = req[j];
				req[j] = temp;
			}
		}
	}
	int a,c;
	printf("enter read write arm: ");
	scanf("%d",&a);
	printf("enter no of cylinders: ");
	scanf("%d",&c);
	int k;
	for(k=0;k< n;k++){
		if(req[k] == a){
			break;
		}
	}
	int i = k-1;
	int j = k+1;
	int heads = 0;
	int t;
	printf("enter 0 to right and 1 to left: ");
	scanf("%d",&t);
	if(t==0){
		while(j < n){
			printf("%d --> %d  ,",a,req[j]);
			heads += abs(a-req[j]);
			a = req[j++];
		}
		heads+= abs(a - (c-1));
		a = (c-1);
		k = 0;
		printf("%d --> %d  ,",a,0);
		heads += a;
		a=0;
		while(k <= i){
			printf("%d --> %d  ,",a,req[k]);
			heads += abs(a-req[k]);
			a = req[k++];
		}	
	}
	else{
		while(i >= 0){
			printf("%d --> %d  ,",a,req[i]);
			heads += abs(a-req[i]);
			a = req[i--];
		}
		printf("%d --> %d  ,",a,0);
		heads+= abs(a - 0);
		a = 0;
		k = n-1;
		printf("%d --> %d  ,",a,c-1);
		heads += (c-1);
		a=c-1;
		while(k >= j){
			printf("%d --> %d  ,",a,req[k]);
			heads += abs(a-req[k]);
			a = req[k--];
		}
	}
	
	printf("\nno of head movements: %d\n",heads);
	
}
