#include<stdio.h>
int main(){
int n;
scanf("%d", &n);
int sum=0, i, x;
for(i=1; i<=n; i++){
	scanf("%d", &x);
	if(i%2==1){
		sum=sum+x*x;
	}
	}
printf("%d\n", sum);
}
