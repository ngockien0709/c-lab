/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nguye
 *
 * Created on June 15, 2020, 10:26 AM
 */

#include <cstdlib>
#include<stdio.h>
#include<math.h>
#include<string.h>
using namespace std;

/*
 * 
 */

void display() {
    printf("\n1.	Convert binary number to decimal number");
    printf("\n2.	Convert octal number to decimal number");
    printf("\n3.	Convert hexadecimal number to decimal number");
    printf("\n4.	Exit\n");
}

int convertBinToDec(int n) {
    int p = 0, dec = 0;
    while (n > 0) {
        dec += n % 10 * pow(2, p);
        ++p;
        n /= 10;
    }
    return dec;
}

int convertOctToDec(int n) {
    int p = 0, dec = 0;
    while (n > 0) {
        dec += n % 10 * pow(8, p);
        ++p;
        n /= 10;
    }
    return dec;
}

int convertHexToDec(char hex[]) {
    int leng = strlen(hex);
    int p = 0, dec = 0;
    for (int i = leng - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * pow(16, p);
            p++;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * pow(16, p);
            p++;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * pow(16, p);
            p++;
        }
    }
    return dec;
}

int main(int argc, char** argv) {
    int n;
    char c[100];
    char key;
    int choice;
     do{
        display();
        printf("choice = ");
        scanf("%d", &choice);
        switch (choice) {

            case 1:
                printf("n = ");
                scanf("%d", &n);
                printf("\ndecimal= %d", convertBinToDec(n));
                break;
            case 2:
                printf("\nn = ");
                scanf("%d", &n);
                printf("\ndecimal= %d", convertOctToDec(n));
                break;
            case 3:
                printf("c = ");
                scanf("%s", &c);
                printf("\ndecimal= %d", convertHexToDec(c));
                break;

            case 4: break;
            default: break;
        }
        //        if(choice == 4) break;
        printf("\nPress enter to continue, Esc to return the main menu \n key =");
        fpurge(stdin);
        scanf("%s", &key);
//                key = getchar();
//        if (key == 27) {
//            break;
//        }
    }   while(key != 27 );  
   
  return 0;
}

