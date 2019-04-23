#include<stdio.h>
#define INFINITY 9999
#include<stdlib.h>

struct Edge{
	int u; //start
	int v; //end
	int w; //value
	
	};

struct Graph{
	int V;
	int E;
	struct Edge *edge;
	};
	void display(int arr[], int size) {
	int i;
	for(i = 0; i < size; i ++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void bellmanford(struct Graph *g, int source) {
	int i, j, u, v, w;

	int tV = g->V;
	
	int tE = g->E;
	
	int d[tV];
	
	int p[tV];
	
	for (i = 0; i < tV; i++) {
		d[i] = INFINITY;
		p[i] = 0;
	}
	
	//mark the source vertex
	d[source] = 0;
	
	//step 2: relax edges |V| - 1 times
	for(i = 1; i <= tV-1; i++) {
		for(j = 0; j < tE; j++) {
			//get the edge data
			u = g->edge[j].u;
			v = g->edge[j].v;
			w = g->edge[j].w;
			
			if(d[u] != INFINITY && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				p[v] = u;
			}
		}
	}
	
	//step 3: detect negative cycle
	//if value changes then we have a negative cycle in the graph
	//and we cannot find the shortest distances
	for(i = 0; i < tE; i++) {
		u = g->edge[i].u;
		v = g->edge[i].v;
		w = g->edge[i].w;
		if(d[u] != INFINITY && d[v] > d[u] + w) {
			printf("Negative weight cycle detected!\n");
			return;
		}
	}
	
	//No negative weight cycle found!
	//print the distance and predecessor array
	printf("Distance array: ");
	display(d, tV);
	printf("Predecessor array: ");
	display(p, tV);
}


		
int main(){
	struct Graph *g= (struct Graph*)malloc(sizeof(struct Graph)); 
	printf("\nEnter the number of vertices: ");
	scanf("%d",&g->V);
	printf("\nEnter the number of Edges: ");
	scanf("%d",&g->E);
	g->edge=(struct Edge*)malloc(g->E* sizeof(struct Graph));
	int t=g->E;
	for(int i=0;i<t;i++)
		{
		printf("\nFor Edge %d:",i+1);
		printf("\nEnter the Starting vertex: ");
		scanf("%d",&g->edge[i].u);
		printf("\nEnter the destination vertex: ");
		scanf("%d",&g->edge[i].v);
		printf("\nEnter the Weight: ");
		scanf("%d",&g->edge[i].w);
		}
		bellmanford(g,0);
	}
