#include <stdio.h>
#include <float.h>


double inputCheck(char msg[], char error[], double min, double max){
	double num;
	int check; 
	char c;
	do{
		printf("%s",msg);
		check=scanf("%lf%c", &num, &c);//Returns the value of an integer
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
int main(){
	

	int month=0;
	double mortgage,percent,payment;
  	mortgage=inputCheck("What is the value left on the mortgage?\n","Enter again!!\n",0.0,DBL_MAX);
  	percent=inputCheck("What is the annual interest rate of the loan, in percent?\n","Enter again!!\n",0.0,DBL_MAX);
  	payment = inputCheck("What is the monthly payment?\n","Enter again!!!\n",0.0,DBL_MAX);
  	percent/=12;
  	printf("Month\tPayment  Amount Owed\n");
  	
  	do{
  		mortgage=mortgage+mortgage*percent/100;//tinh lai xuat
  		if(mortgage>payment){
  			mortgage=mortgage-payment;
		}else{
			payment=mortgage;
			mortgage=0;
		}
		month++;
		printf("%d\t%0.2lf  %0.2lf\n",month,payment,mortgage);	
	}while(mortgage!=0);
  	

	return 0;
}

