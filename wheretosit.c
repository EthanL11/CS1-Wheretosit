#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//global variables
int people,donotwanttosit;
char customers[10][20];
int ToPop[10];
int avoid[10][10];
int counter=0;

//checks permutation
int isValid(int personInSeat[],int length){
	//validates if there is person with popcorn and dontwanttosit
	for(int i=0;i<length;i++){
		int here=personInSeat[i];
		int left=personInSeat[i-1];
		int right=personInSeat[i+1];
		int popcorn=0;
		//checks if person has popcorn
		if(ToPop[here]){
			popcorn=1;
		}
		if(i>0&&ToPop[left]){
			popcorn=1;
		}
		if(i+1<length&&ToPop[right]){
			popcorn=1;
		}
		if(!popcorn){
			return(0);
		}
		if(i>0&&avoid[here][left]){
			return(0);
		}
		if(i+1<length&&avoid[here][right]){
			return(0);
		}
	}
	return(1);
}

//permutation
void printperms(int* perm,int* used,int k,int n){
	//checks if permutation is valid
	if (k==n&&isValid(perm,n)){
		counter++;
	}

	for(int i=0;i<n;i++){
		if (!used[i]){
			used[i]=1;
			perm[k]=i;
			printperms(perm,used,k+1,n);
			used[i]=0;
		}
	}
}

int main()
{
	scanf("%d %d",&people,&donotwanttosit);
	for(int i=0;i<people;i++){
		scanf("%s %d",customers[i],&ToPop[i]);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			//setting avoid equal to zero
			avoid[i][j]=0;
		}
	}
	for(int i=0;i<donotwanttosit;i++){
		//find the avoid in the list & store them
		char avoidOne[20];
		char avoidTwo[20];
		scanf("%s %s",avoidOne,avoidTwo);
		//store avoid
		int avoidFound;
		int avoidFound2;
		for(int j=0;j<people;j++){
			if(strcmp(customers[j],avoidOne)==0){
				avoidFound=j;
			}
			if(strcmp(customers[j],avoidTwo)==0){
				avoidFound2=j;
			}
		}
		avoid[avoidFound][avoidFound2]=1;
		avoid[avoidFound2][avoidFound]=1;
	}
	int perm[10];
	int used[10];
	for(int i=0;i<10;i++)
	{
		used[i]=0;
	}
	printperms(perm,used,0,people);
	printf("%d\n", counter);
	return 0;
}
