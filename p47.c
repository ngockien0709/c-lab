/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 10, 2020, 9:08 PM
 */

#include <stdio.h>
#include <stdlib.h>

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
void display(){
    printf("\n******************************************");
    printf("\n1 - Add a student.");
    printf("\n2 - Remove a student.");
    printf("\n3 - Search a student.");
    printf("\n4 - Print list in an ascending folder.");
    printf("\n5 - Exit.");
    printf("\n******************************************");
}
void addStudent(char array[][50],int *size){
    if(*size==100) printf("The list has full. It cannot add a new student.\n");
    else{
        printf("Enter new student name: " );
        gets(array[*size]);
        int temp = *size;
        *size = temp+1;
        printf("Student has been added to list successfully!\n");
    }
}
void removeStudent(char array[][50], int *size){
    char name[50];
    printf("Enter student name to remove: ");
    gets(name);
    int check = 0;//check =0 nghia la trong mang ko co ten hoc sinh nao bang voi name, bang 1 nghia la co
    int i=0;
    while(i<*size){
        if(strcmp(array[i],name)==0){
            check = 1;
            for(int j = i;j<*size-1;j++){
                strcpy(array[j],array[j+1]);
            }
            int temp = *size;
            *size = temp -1;
            printf("Student name has been removed from list successfully!\n");
        }
        i++;
    }
    if(check ==0) printf("Student name doesn’t exist in list.\n");
}
int getStudentIndex(char array[][50],int size){
    char name[50];
    printf("Enter student name to search: ");
    gets(name);
    for(int i=0;i<size;i++){
        if(strcmp(array[i],name)==0) return i;
    }
    return -1;
}
//In ra mang chua cac hoc sinh
void displayStudent(char array[][50],int size){
    printf("Total student: %d\n",size);
    for(int i=0;i<size;i++){
        printf("%d. %s\n",i+1,array[i]);
    }
}
void sortAscendingByName(char array[][50],int size){
    for (int i=size-1;i>=0;i--){
        for (int j=0;j<i;j++){
            if(strcmp(array[j],array[j+1])>0){
                char temp[50];
                strcpy(temp,array[j]);
                strcpy(array[j],array[j+1]);
                strcpy(array[j+1],temp);
            }
        }
    }
}
int main(int argc, char** argv) {
    printf("============= Student Management =============\n");
    //char array[100][50]
    //100 la so phan tu cua array
    //50 la do dai cua string
    char array[100][50];
    int size = 0; //size = 0 nghia la array con trong, size = 100 nghia la array full, ko the them hs nua
    while(1){
        display();
        printf("\n\nEnter your choice: ");
        int choice = getInteger(1,5);
        int index;
        switch(choice){
            case 1:
                addStudent(array[50],&size);
                break;
            case 2:
                removeStudent(array[50],&size);
                break;
            case 3:
                index = getStudentIndex(array[50],size);
                if (index!=-1) 
                    printf("The position student name in list is %d\n",index+1);
                else printf("Student name doesn’t exist in list.\n");
                break;
            case 4:
                sortAscendingByName(array[50],size);
                displayStudent(array[50],size);
                break;
            case 5: 
                break;
        }
        if(choice==5) break;
    }
    return (EXIT_SUCCESS);
}