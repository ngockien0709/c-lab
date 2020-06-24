/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 3, 2020, 8:46 PM
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
void getDecimalNumber(int *decimal){
    printf("\tEnter a positive number: ");
    *decimal = getInteger(1,INT_MAX);
}
void convertDecimalToBinary(int decimal, int binary[], int *size){
    int i=0;
    while(decimal>0){
        binary[i] = decimal%2;
        decimal=decimal/2;
        i++;
    }
    *size=i;
 
}
void display(int binary[], int size){
    printf("\tBinary number: ");
    for(int i=size-1;i>=0;i--){
        printf("%d",binary[i]);
    }
}
int main(int argc, char** argv) {
    while(1){
        int decimal, size;
        int binary[50];
        printf("Convert Decimal to Binary program\n");
        getDecimalNumber(&decimal);
        convertDecimalToBinary(decimal,binary,&size);
        display(binary,size);
        printf("\nPress any key to do another conversation.");
        char key = getchar();
    }
    return (EXIT_SUCCESS);
}