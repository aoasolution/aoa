#include<stdio.h>
#define max 100

void merge(int arr[],int beg,int mid,int end){
	int i=beg;
	int j=mid+1;
	int index=beg;
int temp[max];
	while((i<=mid)&&(j<=end)){
		if(arr[i]<arr[j]){
			temp[index]=arr[i];
			i++;
			}
			else{
				temp[index]=arr[j];
				j++;
				}
			index++;
		}
		if(i>mid){
			while(j<=end){
				temp[index]=arr[j];
				j++;
				index++;
				}
			}
	else{
			while(i<=mid){
				temp[index]=arr[i];
				i++;
				index++;
				}
			}
			for(int h=beg;h<index;h++){
				arr[h]=temp[h];
				}
	}
	
void merge_sort(int arr[],int low,int high){
	int mid;
	if(low<high){
	mid=(low+high)/2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid+1,high);
	int i=0;
	merge(arr,low,mid,high);
	printf("\nAfter pass %d:",i+1);
	i+=1;
	for(int j=0;j<high+1;j++){
		printf("\t%d",arr[j]);
		}
		}
	}



	void accept(int arr[], int n){
	
	printf("\nEnter the elements: ");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		}	
		}

void display(int arr[], int n){
	printf("\nThe sorted elements are: ");
	for(int i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	}

int main(){
	int arr[max],n;
	printf("\nEnter the size:");
	scanf("%d",&n);
	accept(arr,n);
	merge_sort(arr,0,n-1);
	display(arr,n);
	}
	
