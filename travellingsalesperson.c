#include<stdio.h>
#define MAX 10
int visited[MAX],cost[MAX][MAX],n,min=9999;

void tsp(int city,int total,int count) {
int i;
visited[city]=1;
if(count==n && cost[city][0]) {
if(total+cost[city][0]<min) min=total+cost[city][0];
visited[city]=0;
return;
}
for(i=0;i<n;i++) {
if(!visited[i] && cost[city][i]) {
tsp(i,total+cost[city][i],count+1);
}
}
visited[city]=0;
}

void main() {
int i,j;
printf("Enter no of cities\n");
scanf("%d",&n);
printf("Enter cost matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
scanf("%d",&cost[i][j]);
for(i=0;i<n;i++) visited[i]=0;
tsp(0,0,1);
printf("Minimum cost: %d\n",min);
}
