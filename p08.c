/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: DELL
 *
 * Created on June 11, 2020, 9:56 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 
 */
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
void checkDupplicate(int flag[], char string[]){
    // a s f g A a f s
    // 1 1 1 1 1 1 1 1
    // 2 1 1 1 2 1 1 1
    // 3 1 1 1 2 2 1 1
    // 3 2 2 1 2 2 2 2
    for(int i = 0;i<strlen(string);i++){
        if(flag[i]==1){
            for(int j = i+1;j<strlen(string);j++){
                if(string[i]==string[j]||string[i]==string[j]-32||string[i]==string[j]+32){
                    flag[i]++;
                    flag[j]++;
                }
            }
        }
    }
}
void display(int flag[], char string[]){
    printf("Found characters: ");
    for(int i=0;i<strlen(string);i++){
        if(flag[i]==1) printf("%c  ",string[i]);
    }
}
int main(int argc, char** argv) {
    char string[50];
    while(1){
        printf("Please enter a string: ");
        fpurge(stdin);
        gets(string);
        //nhung phan tu xuat hien 1 lan se co gia tri mang co la 1
        int flag[strlen(string)];
        for(int i=0;i<strlen(string);i++){
            flag[i]=1;
        }
        checkDupplicate(flag,string);
        display(flag,string);
        printf("\nPress Enter to continue, ESC to exit.");
        if(getButton()==27) break;
    }
    return (EXIT_SUCCESS);
}