#include<stdio.h>
int main(){
	int n,start[10],length[10];
	char name[10][20];
	printf("enter number of files: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("enter file name: ");
		scanf("%s",name[i]);
		printf("\n enter starting block: ");
		scanf("%d",&start[i]);
		printf("\n enter length of file: ");
		scanf("%d",&length[i]);
	}
	printf("\n file\t start\t length\t allocated blocks\n");
	for(int i=0;i<n;i++){
		printf("%s\t %d\t %d\t",name[i],start[i],length[i]);
		for(int j=0;j<length[i];j++){
			printf("%d ",start[i]+j);
		}
		printf("\n");
	}
	return 0;
}
