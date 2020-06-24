/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 4, 2020, 9:50 PM
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
void dislayMenu(){
    printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("MENU\n");
    printf("-------------------------");
    printf("\n1- Processing date data");
    printf("\n2- Character data");
    printf("\n3- Exit");
}
void getDate(int *day, int *month, int *year){
    printf("Enter day: ");
    *day = getInteger(1,31);
    printf("Enter month: ");
    *month = getInteger(1,12);
    printf("Enter year: ");
    *year = getInteger(1,9999);
}
int checkNamNhuan(int year){
    //Nam nhuan la nam chia het cho 4, nhung ko chia het cho 100
    if(year%4!=0) return 0;
    if(year%100==0) return 0;
    return 1;
}
int checkDate(int day, int month, int year){
    if(month==4||month==6||month==9||month==11){
        if(day==31) return 0;
    }
    if(month==2){
        if(checkNamNhuan(year)==0){
            if(day>28) return 0;
        }
        else if(day>29) return 0;
    }
    return 1;
}
void getChar(char *begin, char *end){
    while(1){
        printf("Please input characters: ");
        char enter;
        int check = scanf("%c%c%c",&*begin,&*end,&enter);
        if(check==3&&enter=='\n'){
            return;
        }
        else printf("Input is not valid!\n");
        fpurge(stdin);
    }
}
void displayCharacter(char begin, char end){
    if(begin<end){
        char temp =begin;
        begin =end;
        end = temp;
    }
    for(int i = (int)begin;i>=(int)end;i--){
        printf(" %c : %d\n",(char)i,i);
    }
}
int main(int argc, char** argv) {
    while(1){
        int day, month, year;
        char begin, end;
        int out =0;
        dislayMenu();
        printf("\nEnter your choice: ");
        int choice;
        choice = getInteger(1,3);
        switch(choice){
            case 1:
                getDate(&day,&month,&year);
                if(checkDate(day,month,year)==1) printf("This date is valid!");
                else printf("This date is not valid!");
                break;
            case 2:
                getChar(&begin,&end);
                displayCharacter(begin,end);
                break;
            case 3:
                out = 1;
                break;
        }
        if(out==1) break;
    }
    return (EXIT_SUCCESS);
}