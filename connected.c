#include<stdio.h>  

int a[20][20], visited[20], n;   

void dfs(int v); 
int connected();  

void main(){    
 int i,u,v,e,c;  
 printf("Enter vertices & edges: ");
  scanf("%d%d", &n, &e);    
 for(i=1;i<=e;i++)
 {  
  printf("Enter edge (u v): ");   
  scanf("%d%d", &u, &v);    
  a[u][v]=a[v][u]=1;  
 }  
 c=connected();    
 printf("Connected Components: %d", c); 
}  

int connected()
{     
 int i,count=0;   
 for(i=1;i<=n;i++) 
   visited[i]=0;  
 for(i=1;i<=n;i++) 
  if(!visited[i])
  {
    dfs(i); count++;
  }   
 return count; 
}  

void dfs(int v)
{    
 int i;
  visited[v]=1;    
 for(i=1;i<=n;i++) 
  if(a[v][i] && !visited[i]) 
   dfs(i);  
}
