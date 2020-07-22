/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguye
 *
 * Created on July 22, 2020, 4:57 PM
 */

#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */

void displaySelection() {
    printf("\n1- Add a value");
    printf("\n2- Search a value");
    printf("\n3- Remove the first existence of a value");
    printf("\n4- Remove all existences of a value");
    printf("\n5- Print out the array ");
    printf("\n6- Sort the array in ascending order (positions of elements are preserved)");
    printf("\n7- Sort the array in descending order (positions of elements are preserved)");
    printf("\nOthers- Quit");
}

void addValues(int a[], int &size) {
    printf("enter values: ");
    scanf("%d", &a[size++]);
}

void SearchValues(int a[], int size) {
    int num;
    int check = 0;
    printf("\nenter value to search: ");
    scanf("%d", &num);
    for (int i = 0; i < size; i++) {
        if (a[i] == num) {
            printf("\nthis values at: %d", i + 1);
            check = 1;
        }
    }
    if (check == 0) {
        printf("\nthis value not exits in array");
    }

}

void swap(int &a, int &b) {
    int c = a;
        a = b;
        b = c;
}

void RemoveFirstValues(int a[], int &size) {
    int num;
    int check = 0;
    printf("\nenter value to remove: ");
    scanf("%d", &num);
    for (int i = 0; i < size; i++) {
        if (a[i] == num) {
            for(int j=i;j<size;j++){
            swap(a[j] , a[j + 1]);
//            a[j] = a[j + 1];
            }
             size--;
            check = 1;
            break;
        }
        
    }
    if (check == 0) {
        printf("\nthis value not exits in array");
    }else {
        printf("\nDelete done!!!");
    }
}

void RemoveAllValues(int a[], int &size) {
    int num;
    int check = 0;
    printf("\nenter value to remove: ");
    scanf("%d", &num);
    for (int i = 0; i < size; i++) {
        if (a[i] == num) {
            for(int j=i;j<size;j++){
            swap(a[j] , a[j + 1]);         
            
        }
         size--; 
         check = 1;
    }
    }
    if (check == 0) {
        printf("\nthis value not exits in array");
    }else {
        printf("Delete done!!!");
    }

}

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }
}



void sortAscending(int a[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    printArray(a,size);
}

void sortDescending(int a[],int size){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }
        }
    }
    printArray(a,size);
}

int main(int argc, char** argv) {
    int a[100];
    int size=0,choice;
    do{
        displaySelection();
        printf("\nchoice = ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                addValues(a,size);
                break;
            case 2:
                SearchValues(a,size);
                break;
            case 3:
                RemoveFirstValues(a,size);
                break;
            case 4:
                RemoveAllValues(a,size);
                break;
            case 5:
                printArray(a,size);
                break;
            case 6: 
                sortAscending(a,size);
                break;
            case 7: 
                sortDescending(a,size);
                break;
            default: break;
        }
            
    }while(choice<=7);
    

    return 0;
}

