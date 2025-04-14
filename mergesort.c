#include<stdio.h>  

void mergesort(int a[],int low,int high);  
void merge(int a[],int low,int mid,int high);  

void main(){   
 int a[20],n,i;    
 printf("Enter size: ");
  scanf("%d", &n);  
 printf("Enter elements: "); 
 for(i=0;i<n;i++)
   scanf("%d", &a[i]);  
 printf("Before sorting:\n"); 
 for(i=0;i<n;i++) 
   printf("%d ", a[i]);  
 mergesort(a, 0, n-1);   
 printf("\nAfter sorting:\n"); 
 for(i=0;i<n;i++)
   printf("%d ", a[i]);   
}  

void mergesort(int a[],int low,int high){     
 if(low<high){  
  int mid=(low+high)/2;     
  mergesort(a,low,mid);    
  mergesort(a,mid+1,high);  
  merge(a,low,mid,high);   
 }  
}   

void merge(int a[],int low,int mid,int high)
{  
 int i=low,j=mid+1,k=low,b[20],x;    
 while(i<=mid && j<=high) 
  b[k++] = a[i] < a[j] ? a[i++] : a[j++];  
 while(i<=mid)
   b[k++] = a[i++];  
 while(j<=high)
   b[k++] = a[j++];  
 for(x=low; x<=high; x++) 
  a[x] = b[x];  
}
