#include<stdio.h>
#include<conio.h>
int main(){
	int i, j, c=0;
	int n = 5;
	char np[5]="NepaL";
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			printf(" ");
		}
		for(j=0;j<2*i+1;j++){
			printf("%c",np[i]);
			c--;
		}
		printf("\n");
	}
	getch();
	return 0;
}
