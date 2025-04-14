#include<stdio.h>  

void dfs(int v);  

int a[20][20], visited[20], n;  

void main(){  
 int v,i,j;  
 printf("Enter number of vertices: "); 
  scanf("%d", &n);  
 printf("Enter adjacency matrix:\n");   
 for(i=1;i<=n;i++) for(j=1;j<=n;j++)
   scanf("%d", &a[i][j]);  
 for(i=1;i<=n;i++)
   visited[i]=0;    
 printf("Enter starting vertex: ");
  scanf("%d", &v);  
 printf("DFS Traversal: ");  
 dfs(v);  
}  

void dfs(int v) 
{  
 int i;   
 printf("%d ", v); 
  visited[v]=1;  
 for(i=1;i<=n;i++)   
  if(a[v][i]!=0 && visited[i]==0) 
   dfs(i);  
}
