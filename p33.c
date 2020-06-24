/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.c
 * Author: DELL
 *
 * Created on June 3, 2020, 8:05 PM
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
    printf("\tNumber of element s =  ");
    *size = getInteger(1,INT_MAX);
}
void inputElement(int array[], int size){
    array = (int *)realloc(array,size);
    for(int i=0;i<size;i++){
        printf("\tEnter an integer: ");
        array[i] = getInteger(INT_MIN,INT_MAX);
    }
}
void calculateSum(int array[], int size, int *sum){
    *sum=0;
    for(int i=0;i<size;i++){
        *sum+=array[i];
    }
}
void display(int sum){
    printf("\tSum = %d",sum);
}
int main(int argc, char** argv) {
    while(1){
        int *array = (int*)malloc(0*sizeof(int));
        int size, sum=0;
        printf("Dynamic memory allocation\n");
        getSize(&size);
        inputElement(array,size);
        calculateSum(array,size,&sum);
        display(sum);
        printf("\nPress any key to continue.");
        char key = getchar();
        free(array); //Giai phong bo nho dong cua mang dong
    }
    return (EXIT_SUCCESS);
}

