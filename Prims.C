#include<stdio.h>

int main(){
	int v;
	
	printf("\nEnter the number of vertices:");
	scanf("%d",&v);
	int g[v][v];
	int visited[v];
	printf("\nEnter the adjacency matrix ");
	for(int i=0;i<v;i++){
	for(int j=0;j<v;j++){
	scanf("%d",&g[i][j]);
	}	
		}
	for(int i=0;i<v;i++){
		visited[i]=0;
		}
		int s;
	printf("\nEnter the source vertex: ");
	scanf("%d",&s);
	visited[s]=1;
	int x,y,no=0,cost=0;
	printf("\nEdge\t:\tWeight");
	while(no<v-1){
	
	int min=9999;						//Error here. This must be inside the while loop
	for(int i=0;i<v;i++){
		if(visited[i]==1){
			for(int j=0;j<v;j++){
				if(visited[j]==0 && g[i][j]>0){
					if(g[i][j]<min){

						min=g[i][j];
						x=i;
						y=j;
						}
					
					}
				}
			}
		}
		cost+=min;						//error here. Misplaced it inside the internal if statement
		visited[y]=1;
		printf("\n%d-%d\t:",x,y);
		printf("\t%d",min);
	no++;
}
	printf("\nThe total cost is: %d",cost);
	return 0;
	
	}
