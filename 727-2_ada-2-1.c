#include<stdio.h>
int main(){
int n;
scanf("%d", &n);
int min, x, i;
scanf("%d", &min);
for (i=2; i<=n; i++){
	scanf("%d", &x);
	if (x<min){
		min=x;}
	}
printf("%d\n", min);
}
