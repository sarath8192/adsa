#include<stdio.h>
#include<stdlib.h>
void nqueens(int k,int n);
int place(int k,int i);
int x[20],count=0;
void main() {
int n,k=1;
printf("\nEnter no.of queens");
scanf("%d",&n);
nqueens(k,n);
}

void nqueens(int k,int n) {
int i,j;
for(i=1;i<=n;i++) {
if(place(k,i)) {
x[k]=i;
if(k==n) {
count++;
printf("\nsolution %d\n",count);
for(j=1;j<=n;j++) printf("%d ",x[j]);
}
else nqueens(k+1,n);
}
}
}

int place(int k,int i) {
int j;
for(j=1;j<k;j++) {
if(x[j]==i || abs(k-j)==abs(i-x[j])) return 0;
}
return 1;
}
