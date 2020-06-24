/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 3, 2020, 9:29 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * Su dung phuong phap vet can
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
float getFloat(float min, float max){
    float num;
    int check;
    char c;
    //Loop for check input, if input is invalid, ask for input again, else out of loop
    do{
        check=scanf("%f%c", &num, &c);
        //Check the input is valid or not, if this is valid, variable 'check' = 1, else 'check' = 0
        if(check!=2||c != '\n' || num<=min || num>=max){ 
            printf("Please enter a float in range [%f,%f]: ",min, max);
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
void getPackPrice(float *smallPackPrice, float *bigPackPrice){
    printf("What is the cost of small package (in dollars)?\n");
    *smallPackPrice = getFloat(0,500);
    printf("What is the cost of big package (in dollars)?\n");
    *bigPackPrice = getFloat(0,500);
}
void getInvitations(int *invitation){
    printf("How many invitations are you sending out?\n");
    *invitation=getInteger(1,10000);
}
void calculate(float smallPackPrice, float bigPackPrice, int *smallPackQuantity, int *bigPackQuantity, int invitation){
    int maxBigPackQuantity, maxSmallPackQuantity, allPriceTemp;
    if(invitation%200!=0){
        maxBigPackQuantity = invitation/200+1;
    } else maxBigPackQuantity = invitation/200;
    if(invitation%50!=0){
        maxSmallPackQuantity = invitation/50+1;
    } else maxSmallPackQuantity = invitation/50;
    allPriceTemp = maxBigPackQuantity*bigPackPrice;
    *smallPackQuantity = 0;
    *bigPackQuantity = maxBigPackQuantity;
    //bigPackQuantityTemp = So luong cai big package tam thoi
    for(int bigPackQuantityTemp = 0; bigPackQuantityTemp<=maxBigPackQuantity;bigPackQuantityTemp++){
        for(int smallPackQuantityTemp = 0;smallPackQuantityTemp<=maxSmallPackQuantity;smallPackQuantityTemp++){
            if(bigPackQuantityTemp*200+smallPackQuantityTemp*50>invitation){
                if(bigPackQuantityTemp*bigPackPrice+smallPackQuantityTemp*smallPackPrice<allPriceTemp){
                    allPriceTemp = bigPackQuantityTemp*bigPackPrice+smallPackQuantityTemp*smallPackPrice;
                    *smallPackQuantity = smallPackQuantityTemp;
                    *bigPackQuantity = bigPackQuantityTemp;
                }
            }
        }
    }
}
void display(float smallPackPrice, float bigPackPrice, int smallPackQuantity, int bigPackQuantity){
    printf("\nYou should order %d small package(s)",smallPackQuantity);
    printf("\nYou should order %d big package(s)",bigPackQuantity);
    printf("\nYour cost for invitations will be $%0.2f",smallPackPrice*smallPackQuantity+bigPackPrice*bigPackQuantity);
}
int main(int argc, char** argv) {
    float smallPackPrice, bigPackPrice;
    int smallPackQuantity, bigPackQuantity, invitation;
    getPackPrice(&smallPackPrice,&bigPackPrice);
    getInvitations(&invitation);
    calculate(smallPackPrice,bigPackPrice,&smallPackQuantity,&bigPackQuantity,invitation);
    display(smallPackPrice,bigPackPrice,smallPackQuantity,bigPackQuantity);
    return (EXIT_SUCCESS);
}

