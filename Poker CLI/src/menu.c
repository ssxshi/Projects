#include <stdio.h>

#include "../include/menu.h"
#include "../include/utils.h"

int show_menu(){
    system("cls");

    printf("Welcome to CLI Poker!\n");
    printf("*************************\n");
    printf("Select a gamemode\n");
    printf("1] vs. CPU\n");
    printf("2] vs. Player\n");
    printf("*************************\n");

    char option_buffer[2];
    if (fgets(option_buffer, sizeof(option_buffer), stdin) == NULL){
        printf("\nInvalid input! Try again!\n");
        return -1;
    }
    
    option_buffer[1] = '\n';

    int option = 0;
    if (sscanf(option_buffer, "%d", &option) != 1){
        printf("\nError parsing input! Try again!\n");
        return -1;
    }

    if (option == 2){
        printf("\nMultiplayer is currently not available! Try another gamemode!\n");
        return -1;
    }

    return option;
}