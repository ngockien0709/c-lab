/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguye
 *
 * Created on June 17, 2020, 4:31 PM
 */

#include <cstdlib>
#include<stdio.h>
#include <climits>
using namespace std;

/*
 * 
 */

int checkInput(int min, int max){
    int check=1;
    int n;
    char c;
    
    do{
        
        scanf("%d%c",&n,&c);
        if(n>max||n<min||c!='\n'){
            printf("please enter number from %d to %d :",min,max);
            fpurge(stdin);
            check=0;
        }
        else {
            check=1;
            break;
        }
    }while(check==0);
    return n;
}

void display(){
    printf("\n1-out first primes of the inputted number");
    printf("\n2-check a Fibonacci number");
    printf("\n3-sum of digits in a positive natural number");
}
   
int checkPrimes(int n){
    if(n<2) return 0;
    for(int i=2;i<n ;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void displayPrime(int num){
    printf("number of primes: ");
    num = checkInput(2,50);
    int count =0;
    int i=2;
    while(1){
        if(checkPrimes(i)){
            printf("%d ",i);
            count++;
            if(count==num) break;
        }
        i++;
        }
}

int checkFibo(int n){
    printf("number tested: ");
    n = checkInput(0,1000);
    if(n==1){
        return 1;
    }
    int fibo1=1;
    int fibo2=1;
    int fibo3=fibo1+fibo2;
    while(fibo3<n){
        fibo1=fibo2;
        fibo2=fibo3;
        fibo3=fibo1+fibo2;
    }
    if(fibo3 == n) return 1;
    else return 0;
}

int sumOfDigits(int n){
    printf("enter an interger: ");
    n = checkInput(0,INT_MAX);
    int sum = 0;
    while(n!=0){
        sum += n%10;
        n/=10;
    }
    return sum;
}

int main(int argc, char** argv) {
    int n;
//    
//    
//    
    
    display();
    printf("\nchoose an option: ");
    int choice = checkInput(1,3);
    switch(choice){
        case 1: 
            displayPrime(n);
            break;
           
        case 2:
            if(checkFibo(n)){
                printf("it's a fibonacci term");
            } else{
                printf("it's not a fibonacci term");
            }
            break;
            
        case 3:
            printf("sum of digits: %d",sumOfDigits(n));
    }
    return 0;
}

