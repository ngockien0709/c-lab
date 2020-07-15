#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int inputCheck(int min, int max){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||c != '\n' || num<min || num>max){
           	printf("Please enter again!!!\n\tEnter a positive number: ");
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

int main(){
	int n,size;
	
	
	while(1){
		size=0;
		printf("Convert Decimal to Binary program\n");
		printf("\tEnter a positive number: ");
		n=inputCheck(1,INT_MAX);
		printf("\tBinary Number: ");
//		char A[32];
//		while(n>0){
//			A[size]=n%2+48;
//			size++;
//			n/=2;
//		}
//		for(int i = size-1;i>=0;i--){
//			printf("%c",A[i]);
//		}
		int A[100];
		while(n>0){
			A[size]=n%2;
			size++;
			n=n/2;
		}

//		int *A=(int *) calloc(size,sizeof(int));
//		while(n>0){
//			A= (int *) realloc(A,++size*sizeof(int));
//			A[size-1]=n%2;
//			n=n/2;
//		}
		for(int i=size-1;i>=0;i--){
			printf("%d",A[i]);
		}
//		free(A);
		printf("\nPress any key to do another conversion.\n");
		char k =getchar();
		printf("\n");
	}
}
