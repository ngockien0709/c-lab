#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int inputCheck(int min, int max,char err[]){
    int num;
    int check;
    char c;
    do{
        check=scanf("%d%c", &num, &c);//Returns the value of an integer
        if(check!=2||(c != ' '&&c!='\n')|| num<min || num>max){
            printf("%s",err);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
}

int main() {
	int row,col,i,j;
  printf("Matrix Add");
  printf("\nAccept size : ");
  row=inputCheck(1,INT_MAX,"row must be positive integer: ");
  col=inputCheck(1,INT_MAX,"column must be positive integer: ");
  int m1[row][col],m2[row][col],m[row][col];
  printf("Accept matrix m1:\n");
  for(i=0;i<row;i++){
  	for(j=0;j<col;j++){
  		m1[i][j]=inputCheck(INT_MIN,INT_MAX,"Enter a positive integers:");
	  }
  }
  printf("Accept matrix m2:\n");
  for(i=0;i<row;i++){
  	for(j=0;j<col;j++){
  		m2[i][j]=inputCheck(INT_MIN,INT_MAX,"m2 Enter a positive integers:");
	  }
  }
  printf("m = m1 + m2:\n");
  
  for(i=0;i<row;i++){
  	for(j=0;j<col;j++){
  		m[i][j]=m1[i][j]+m2[i][j];
  		printf("%d\t",m[i][j]);
	  }
	  printf("\n");
  }
  	
  
  
  
  
  return 0;
}

