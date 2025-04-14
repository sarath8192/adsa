#include<stdio.h>  

#define INF 9999  

void dijkstra(int[][10], int, int);    

void main(){    
 int n,s,i,j,ad[10][10];  
 printf("Enter no. of vertices: "); 
  scanf("%d", &n);    
 printf("Enter adjacency matrix:\n");  
 for(i=1;i<=n;i++) 
  for(j=1;j<=n;j++) 
   scanf("%d", &ad[i][j]);    

 printf("Enter source vertex: ");
  scanf("%d", &s);    
 dijkstra(ad, n, s);   
}   

void dijkstra(int ad[][10], int n, int s)
{   
 int cost[10][10], visit[10]={0}, d[10], min, i, j, u=0, v, count=1;  

 for(i=1;i<=n;i++) 
  for(j=1;j<=n;j++) 
   cost[i][j] = (ad[i][j]==0) ? INF : ad[i][j];  

 for(i=1;i<=n;i++) 
  d[i] = cost[s][i];    

 visit[s]=1; 
  d[s]=0;    

 while(count < n)
 {  
  min = INF;   
  for(i=1;i<=n;i++) 
   if(!visit[i] && d[i]<min)
   { 
    min = d[i];
     u = i; 
   }  
  visit[u]=1;   

  for(v=1;v<=n;v++) 
   if(!visit[v] && d[u]+cost[u][v] < d[v]) 
    d[v] = d[u]+cost[u][v];  

  count++;  
 }   

 printf("Vertex\tDistance from Source\n");  
 for(i=1;i<=n;i++) 
  printf("%d\t%d\n", i, d[i]);  
}
