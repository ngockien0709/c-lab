/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 4, 2020, 9:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * 
 */
int getInteger(int min, int max){
    int num;
    int check;
    char c;
    //Loop for check input, if input is invalid, ask for input again, else out of loop
    do{
        check=scanf("%d%c", &num, &c);
        //Check the input is valid or not, if this is valid, variable 'check' = 1, else 'check' = 0
        if(check!=2||c != '\n' || num<min || num>max){ 
            printf("Please enter an integer in range [%d,%d]: ",min, max);
            //Delete the buffer
            fpurge(stdin);
            check=0;
        }
        else{        	
            check=1;
        }
    }while(check==0);
    return num;
}
void displayMenu(){
    printf("\n1-The first primes");
    printf("\n2-Fibonacci element");
    printf("\n3-Sum of digits\n");
}
void displayFirstPrimes(){
    int quantity;
    printf("Number of primes: ");
    quantity = getInteger(1,50);
    int count=0, temp =2;
    while(count<quantity){
        int check =1;
        for(int i=2;i<temp;i++){
            if(temp%i==0) {
                check = 0;
                break;
            }
        }
        if(check==1) {
            count++;
            printf("%d   ",temp);
        }
        temp++;
    }
}
//minh se kiem tra tat ca cac so fibo nho hon hoac bang no, neu gap so bang no, co nghia la
//cai so nhap vao la so fibo, con neu khong thi khong phai
int checkFiboNumber(int number){
    int fibo1, fibo2, fibo3;
    if(number==1) return 1;
    fibo1=1;
    fibo2=1;
    fibo3=fibo1+fibo2; //= 2
    while (fibo3<number){
        fibo1 = fibo2;  // = 1
        fibo2 = fibo3;  // = 2
        fibo3 = fibo1+fibo2;    // = 1+2 = 3  
    }
    if(fibo3 == number) return 1;
    else return 0;
}
int getSumDigit(int number){
    int sum=0;
    //156%10 = 6
    //sum = 0 + 6 = 6
    //156/10 = 15
    while (number>0){
        sum+=number%10;
        number = number/10;
    }
    return sum;
}
int main(int argc, char** argv) {
    while(1){
        displayMenu();
        int number;
        printf("Choose an option: ");
        int choice = getInteger(1,3);
        switch(choice){
            case 1:
                displayFirstPrimes();
                break;
            case 2:
                printf("Number tested: ");
                number = getInteger(1,1000);
                if(checkFiboNumber(number)==1) printf("It's a Fibonacci term\n");
                else printf("It's not a Fibonacci term\n");
                break;
            case 3:
                printf("Enter an integer: ");
                number = getInteger(1,INT_MAX);
                printf("Sum of it's digits: %d\n",getSumDigit(number));
                break;
        }
    }
    return (EXIT_SUCCESS);
}