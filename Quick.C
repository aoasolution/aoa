
#include<stdio.h>
int partition(int a[],int l, int h){
	int pivot=a[l];
	int i=l;
	int j=h;
	while(i<j){
				
	do{
		i++;
		}while(a[i]<=pivot);
	do{
		j--;
		}while(a[j]>pivot);
		
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			}	
		}
		int k=a[l];
			a[l]=a[j];
			a[j]=k;
		
	
	return j;
	}

void quick(int a[],int l, int h){
	int j;
	if(l<h){
	j=partition(a,l,h);
	quick(a,l,j);
	quick(a,j+1,h);
	int i=0;
	printf("\nAfter pass %d:",i+1);
	i++;
	for(int j=0;j<h;j++){
		printf("\t%d",a[j]);	
	}
}
}



int main(){
	int n, a[10];
	printf("\nEnter the size: ");
	scanf("%d",&n);
	printf("\nEnter the elements: ");
	
	for(int i=0;i<n;i++){
	scanf("%d",&a[i]);
	}
	quick(a,0,n);
for(int i=0;i<n;i++){
	printf("\t%d",a[i]);
	}
}

