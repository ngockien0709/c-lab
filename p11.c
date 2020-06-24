/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 11, 2020, 8:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
//Display menu to the screen
void displayMenu(){
    printf("\n================== Convert to decimal ==================");
    printf("\n1. Convert binary number to decimal number");
    printf("\n2. Convert octal number to decimal number");
    printf("\n3. Convert hexadecimal number to decimal number");
    printf("\n4. Exit");
    printf("\n========================================================");
}
void getInput(char number[], int base){
    while(1){
        switch(base){
        case 2:
            printf("Enter binary number: ");
            break;
        case 8:
            printf("Enter octal number: ");
            break;
        case 16:
            printf("Enter hexadecimal number: ");
            break;
        }
        fpurge(stdin);
        gets(number);
        //check = 1 nghia la input thoa man
        int check =1;
        
        //48 tuong ung voi '0'
        for(int i=0;i<strlen(number);i++){
            if(base==2||base==8){   //he co so 2 hoac 8
                if(number[i]>=48+base||number[i]<48){
                    check = 0;
                    printf("Input is not valid, please enter again!\n");
                    break;
                }
            }else{ //No la he co so 16
                //minh co 3 khoang chon
                //khoang 1: 0 - 9
                //khoang 2: A - F
                //khoang 3: a - f
                
                //--------0___9-----A___F------a___f--------//
                if(number[i]<'0'||(number[i]>'9'&&number[i]<'A')||(number[i]>'F'&&number[i]<'a')||number[i]>'f'){
                    check = 0;
                    printf("Input is not valid, please enter again!\n");
                    break;
                }
            }
        }
        if (check ==1) return;
    }
}
//convert dua tren bang ma ASCII
int convertCharToNumber(char c){
    //'0' tuong ung voi 48
    if(c>='0'&&c<='9') return c-48;
    //'A' tuong ung voi 65
    if(c>='A'&&c<='F') return c-55;
    //'a' tuong ung voi 97
    if(c>='a'&&c<='f') return c-87;
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
//base = he co so
void convertToDecimal(int base){
    while(1){
        char number[50];
        int decimal = 0;
        getInput(number,base);
        for(int i = strlen(number)-1;i>=0;i--){
        //a b c   : So
        //0 1 2   : Vi tri
        //12*16^0 + 11*16^1 + 10*16^2
            decimal += convertCharToNumber(number[i])*pow(base,strlen(number)-1-i);
        }
        printf("Decimal number is: %d",decimal);
        printf("\nPress Enter to continue, ESC to return main menu.");
        if(getButton()==27) break;
    }
}
int main(int argc, char** argv) {
    //pow(x,y) tra ve gia tri x^y
    while(1){
        displayMenu();
        printf("\nPlease choose number (1-4): ");
        int choice = getInteger(1,4);
        switch(choice){
            case 1:
                convertToDecimal(2);
                break;
            case 2:
                convertToDecimal(8);
                break;
            case 3:
                convertToDecimal(16);
                break;
            case 4:
                break;
        }
        if(choice ==4) break;
    }
    return (EXIT_SUCCESS);
}