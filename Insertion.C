#include<stdio.h>

void accept(int a[], int n){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		}
	}
	
	
	void insertion(int a[], int n){
		int i,j,temp,k;
		for(i=1;i<n;i++){
		temp=a[i];
		j=i-1;
		while((j>=0)&&(temp<a[j])){
			a[j+1]=a[j];
			j--;
			}
			a[j+1]=temp;
		printf("\nElements after pass %d:",i);
		for(k=0;k<n;k++){
			printf("\t%d",a[k]);
			}
		
		}
		}
		
		
		
int main(){
int a[20];
int n;
printf("\nEnter the size: ");
scanf("%d",&n);
printf("\nEnter the elements: ");
accept(a,n);	
insertion(a,n);

	}

