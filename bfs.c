#include<stdio.h>  

void bfs(int v);  

int a[20][20], queue[20], visited[20], n, front = -1, rear = -1;  

void main(){  
 int v,i,j;  
 printf("Enter number of vertices: ");
  scanf("%d", &n);  
 printf("Enter adjacency matrix:\n");   
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     scanf("%d", &a[i][j]);         
 for(i=1;i<=n;i++)
   visited[i]=0;  
 printf("Enter starting vertex: ");
  scanf("%d", &v);     
 front=rear=0; 
  queue[rear]=v;
  visited[v]=1;      
 printf("BFS Traversal: %d", v);     
 bfs(v); 
}   

void bfs(int v)
{  
 int i; 
 for(i=1;i<=n;i++)
 {  
  if(a[v][i]!=0 && visited[i]==0)
  {  
   queue[++rear]=i;
    visited[i]=1;
    printf("%d", i); 
  }  
 }  
 if(++front <= rear) 
   bfs(queue[front]); 
}
