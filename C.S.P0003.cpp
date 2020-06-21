#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <malloc.h>


int inputCheck(int min, int max,char error[]){
	int num;
	int check; 
	char c;
	do{
		check=scanf("%d%c", &num, &c);//Returns the value of an integer
		fflush(stdin);
        if(check!=2||c != '\n' || num<=min || num>max){
            printf("%s",error);
            fflush(stdin);//Delete buffer
            check=0; //input is a character
        }
        else{
            check=1; //input is a number
        }
    }while(check==0);
    return num;
	
}


void display(int a[],int n){
	int i;
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}

void addNewElement(int *a,int &n,int k){
	int pos;//bien lu vi tri chen
	if(k<a[0]){//k be hon tat ca ca so trong mang nen vi tri chen la 0
		pos=0;
	}else{//tim vi tri can chen
		for(int i=n-1;i>=0;i--){
			if(k>=a[i]){
				pos=i+1;//vi tri chen la vi tri lien sau i
				break;
			}
		}
	}
	for(int i=n;i>=pos;i--){
		a[i]=a[i-1];//lui cac phan tu ve sau den khi gap vi tri can chen
	}
	a[pos]=k;//chen vao dung vi tri
	n++;
}

int main() {
	int n, value;
	int *a;
	printf("Please enter size of array:");
	n=inputCheck(1,INT_MAX,"Enter again!!!\nPlease enter size of array:");
	a=(int *) calloc(n,sizeof(int));
	for(int i=0;i<n;i++){
		printf("Enter element[%d]:",i);
		a[i]=inputCheck(INT_MIN,INT_MAX,"Enter again element:");
	}
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	printf("The array after sorting:\n");
	display(a,n);
	
	printf("Please enter new value:");
	value=inputCheck(INT_MIN,INT_MAX,"Enter again!!!\n");
	
	a=(int *) realloc(a,1+n*sizeof(int));
	
	addNewElement(a,n,value);
	printf("New array:\n");
	display(a,n);
	
	
  	
  
  
  
  return 0;
}

