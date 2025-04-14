#include<stdio.h>  

void main(){   
 int i,j,p[20],d[20],a[20],slot[20],temp,r,total=0,max,n;  
 printf("Enter no. of jobs: "); 
  scanf("%d", &n);  
 printf("Enter profits: ");
  for(i=0;i<n;i++) 
    scanf("%d", &p[i]);  
 printf("Enter deadlines: "); 
  for(i=0;i<n;i++) 
    scanf("%d", &d[i]);  
 max = d[0]; 

 for(i=0;i<n;i++)
 { 
  a[i]=i; 
  if(d[i]>max) max=d[i]; 
 }  

 for(i=0;i<max;i++)
   slot[i]=-1;    

 for(i=0;i<n-1;i++) 
  for(j=0;j<n-1-i;j++)  
   if(p[j]<p[j+1])
   { 
    temp=p[j];
     p[j]=p[j+1]; 
     p[j+1]=temp; 
    temp=a[j]; 
     a[j]=a[j+1];
     a[j+1]=temp; 
   }  

 for(i=0;i<n;i++)
 { 
  j=a[i];
   r=d[j];  
  while(r>=1)
  { 
   if(slot[r-1]==-1)
   { 
    slot[r-1]=j; 
    total+=p[i]; 
    break; 
   } 
   r--; 
  }  
 }  

 printf("Optimal job sequence:\n(");  
 for(i=0;i<max;i++)
 { 
  printf("J%d", slot[i]+1); 
  if(i<max-1)
    printf(" , "); 
 }  
 printf(")\nTotal Profit: %d", total);  
}
