/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 10, 2020, 8:36 PM
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
void displayTable(int number){
    printf("Multiplication table for %d number\n",number);
    for(int i=1;i<=10;i++){
        printf("%d x %d = %d\n",number,i,number*i);
    }
}
char getButton(){
    do{
        char c, button;
        int check = scanf("%c%c",&button,&c);
        {
            if (check!=2||(button!='\n'&&button!=27)){
                printf("Please press Enter or ESC button only!\n");
                fpurge(stdin);
            }
            else return button;
        }
    }while(1);
}
int main(int argc, char** argv) {
    while(1){
        int number, out = 0;
        printf("Please enter a number (1-9): ");
        number = getInteger(1,9);
        displayTable(number);
        printf("\n♥♥♥♥♥♥♥♥♥\n");
        printf("Press Enter to continue, ESC to exit.");
        char button = getButton();
        if(button==27) out =1;
        if(out==1) break;
    }
    return (EXIT_SUCCESS);
}

