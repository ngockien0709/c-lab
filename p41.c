/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 10, 2020, 8:11 PM
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
void getSize(int *size){
    printf("Enter the size of an array: ");
    *size = getInteger(0,100);
}
void getElement(int size, int array[]){
    printf("Enter elements of the array: \n");
    for(int i=0;i<size;i++){
        array[i]=getInteger(INT_MIN,INT_MAX);
    }
}
int getMax(int size, int array[]){
    int max = array[0];
    for(int i=0;i<size;i++){
        if(array[i]>max) max = array[i];
    }
    return max;
}
void display(int size, int array[]){
    printf("\n\nArray elements: \n");
    for(int i=0;i<size;i++){
        printf("%d  ",array[i]);
    }
}
void displayEven(int size, int array[]){
    printf("\n\nArray even values: \n" );
    int count = 0;
    for(int i=0;i<size;i++){
        if(array[i]%2==0) {
            printf("%d  ",array[i]);
            count++;
        }
    }
    if (count==0) printf("No even value in array!");
}
int main(int argc, char** argv) {
    int size;
    int array[100];
    getSize(&size);
    getElement(size,array);
    display(size, array);
    printf("\n\nArray maximum value: \nThe max is %d",getMax(size,array));
    displayEven(size,array);
    return (EXIT_SUCCESS);
}

