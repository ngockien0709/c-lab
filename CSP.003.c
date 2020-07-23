/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 4, 2020, 8:17 PM
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
void inputElement(int array[], int *size){
    printf("Please enter size of array: ");
    *size = getInteger(1,INT_MAX);
    array = (int *)realloc(array,*size);
    for(int i=0;i<*size;i++){
        printf("Enter element[%d]: ",i);
        array[i] = getInteger(INT_MIN,INT_MAX);
    }
}
//Bubble sort
void sortAscending(int array[], int size){
    for(int i=size-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j]=array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void display(int array[], int size){
    for(int i=0;i<size;i++){
        printf("%d   ",array[i]);
    }
}
void addNewElement(int array[], int *size){
    printf("\nPlease enter new value: ");
    int temp = *size+1;
    array = (int *)realloc(array,temp);
    array[*size]=getInteger(INT_MIN, INT_MAX);
    *size = temp;
}
int main(int argc, char** argv) {
    int *array = (int*)malloc(0*sizeof(int));
    int size;
    inputElement(array,&size);
    sortAscending(array,size);
    printf("The array after sorting:\n");
    display(array,size);
    addNewElement(array,&size);
    printf("New array:\n");
    sortAscending(array,size);
    display(array,size);
    free(array);
    return (EXIT_SUCCESS);
}