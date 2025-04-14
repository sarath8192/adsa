#include<stdio.h>  

void maxheap(int a[],int n);  
void heapfy(int a[],int n,int i);  
void deleteNode(int a[],int *n,int value);  

void main(){  
 int a[20],n,i,c=0,val;  
 printf("Enter size: ");
  scanf("%d",&n);  
 printf("Enter elements: ");  
 for(i=1;i<=n;i++)
 {
   scanf("%d",&a[i]); maxheap(a,++c);
 }  
 printf("Heap: "); 
for(i=1;i<=n;i++)
  printf("%d ",a[i]);  
 printf("\nEnter value to delete: ");
  scanf("%d",&val);  
 deleteNode(a,&n,val);  
 printf("After deletion: ");
  for(i=1;i<=n;i++) printf("%d ",a[i]);  
}  

void maxheap(int a[],int n)
{ 
  int i; 
  for(i=n/2;i>0;i--) 
    heapfy(a,n,i);
}  

void heapfy(int a[],int n,int i)
{  
 int temp,large=i,left=2*i,right=2*i+1;  
 if(left<=n&&a[left]>a[large])
   large=left;  
 if(right<=n&&a[right]>a[large]) 
   large=right;  
 if(i!=large)
 {
   temp=a[large]; 
   a[large]=a[i];
   a[i]=temp;
   heapfy(a,n,large);
 }  
}  

void deleteNode(int a[],int *n,int value)
{  
 int i,pos=-1;  
 for(i=1;i<=*n;i++)
   if(a[i]==value)
   { 
     pos=i;
     break;
   }  
 if(pos==-1)
 {
   printf("Value not found!\n");
   return;
 }  
 a[pos]=a[(*n)--];
  maxheap(a,*n);  
}
