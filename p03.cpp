/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguye
 *
 * Created on July 23, 2020, 6:19 AM
 */

#include <cstdlib>
#include<stdio.h>
using namespace std;

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

void input(int a[],int &size){
     printf("\nplease enter size of array: ");
    scanf("%d",&size);
    for(int i=0;i<size;i++){
        printf("\nenter element[%d]: ",i);
        scanf("%d",&a[i]);
//        a[i] = getInteger(1,100);
    }
}

void display(int a[],int size){
    printf("\nthe array after sorting\n"); 
    for(int i=0;i<size;i++){
        printf("%d  ",a[i]);
    }
}

void swap(int &a,int &b){
    int c = a;
        a = b;
        b = c;
} 

void SortAscending(int a[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
               swap(a[i],a[j]);   
            }
        }
    }
}

void addValue(int a[],int &size){
    printf("\nplease enter new value: ");
    scanf("%d",&a[size++]);
} 

int main(int argc, char** argv) {
    
    int size;
    int a[100];
    input(a,size);
    SortAscending(a,size);
    display(a,size);
    addValue(a,size);
    SortAscending(a,size);
    display(a,size);
    return 0;
}

