#include<stdio.h>  

void heapsort(int a[],int n); 
void heapify(int a[],int n,int i);  

void main(){  
 int a[20],n,i;  
 printf("Enter size: "); 
  scanf("%d",&n);  
 printf("Enter elements: ");
  for(i=1;i<=n;i++) 
    scanf("%d",&a[i]);  
 printf("Before sorting: ");
  for(i=1;i<=n;i++) 
    printf("%d ",a[i]);  
 heapsort(a,n);  
 printf("\nAfter sorting: ");
  for(i=1;i<=n;i++) 
    printf("%d ",a[i]);  
}  

void heapsort(int a[],int n)
{  
 int i,temp;  
 for(i=n/2;i>0;i--)
   heapify(a,n,i);  
 for(i=n;i>0;i--)
 {  
  temp=a[1]; a[1]=a[i];
   a[i]=temp;  
  heapify(a,i-1,1);  
 }  
}  

void heapify(int a[],int n,int i)
{  
 int large=i,left=2*i,right=2*i+1,temp;  
 if(left<=n&&a[left]>a[large]) 
   large=left;  
 if(right<=n&&a[right]>a[large])
   large=right;  
 if(large!=i)
 {
   temp=a[large]; 
   a[large]=a[i];
   a[i]=temp;
   heapify(a,n,large);}  
}
