#include <stdio.h> 

int knapsack(int p[], int wt[], int n, int c);   

int max(int a, int b)
{  
 return (a > b) ? a : b; 
} 

void main()
{    
 int n, profit[10], weight[10], capacity, i;  
 printf("Enter number of objects: "); 
  scanf("%d", &n); 
 printf("Enter profits: ");
  for(i=0;i<n;i++) 
    scanf("%d", &profit[i]); 
 printf("Enter weights: ");
  for(i=0;i<n;i++) 
    scanf("%d", &weight[i]); 
 printf("Enter capacity: "); 
  scanf("%d", &capacity); 
 printf("Total profit is: %d", knapsack(profit, weight, n, capacity)); 
} 

int knapsack(int p[], int wt[], int n, int c){ 
 int a[10][10], i, w;     
 for(i=0;i<=n;i++) 
  for(w=0;w<=c;w++) 
   a[i][w] = (i==0 || w==0) ? 0 : 
             (wt[i-1] > w ? a[i-1][w] : 
              max(a[i-1][w], a[i-1][w-wt[i-1]] + p[i-1])); 

 return a[n][c];  
}
