/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguye
 *
 * Created on June 17, 2020, 3:48 PM
 */

#include <cstdlib>
#include<stdio.h>
using namespace std;

/*
 * 
 */

int checkInput(int min,int max){
    int check=1;
    int n;
    char c;
    do{
        scanf("%d%c",&n,&c);
        if(n>max || n<min||c!='\n'){
            printf("please input in range %d - %d :  ",min,max);
            fpurge(stdin);
            check=0;
        }
        else {
            check = 1;
            break;
        }
    }while(check==0);
    return n;
}

void display(){
    printf("\n1-Processing date data");
    printf("\n2-Character data");
    printf("\n3-Quit\n");
}

int checkDate(int &day,int &month,int &year){
    day = checkInput(1,31);
    month = checkInput(1,12);
    year = checkInput(1,9999);
    int leap_year =0;
    if(year %4==0 && year %100 !=0){
        leap_year =1;
    }
    if(month==4||month==6||month==9||month==11){
        if(day==31){
            return 0;
        }
    }
    if(leap_year==1){
      if(day>29) {
          return 0;;
      }  
    }else  if(leap_year=0){
            if(day>28){
                return 0;
            }
        }
    return 1;    
}

int checkCharacter(char &start,char &end){
    char c;
    int check=1;
    do{
    scanf("%c%c%c",&start,&end,&c);
    if(c!='\n'){
      printf("re input: ");  
      fpurge(stdin);
      check=0;   
    }else {
        check =1;
        break;
    }
    }while(check==0);
    
    if(start < end){
        int temp = start;
        start = end;
        end = temp;
    }
    for(int i = int(start);i>=(int)end;i--){
        printf("\n %c : %d ",char(i),i);
    }
}

//int checkData(int start, int end){
//    checkCharacter(start,end);
//    if(start < end){
//        int temp = start;
//        start = end;
//        end = temp;
//    }
//    for(int i = int(start);i>(int)end;i--){
//        printf("%d",i);
//    }
//}

int main(int argc, char** argv) {
//    int day,month,year;
//    if(checkDate(day,month,year)){
//        printf("this date is valid");
//    } else printf("this date is not valid");
    
    char start,end;
    checkCharacter(start,end);
    
    return 0;
}

