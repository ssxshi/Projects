#include <stdio.h>
#include <unistd.h>

#include "../include/game.h"
#include "../include/menu.h"
#include "../include/utils.h"

const char cards[15] = {
    '1', '2', '3', '4', '5', '6', '7',
    '8', '9', '0', 'J', 'K', 'Q', 'A',
    '\0'
};
const char suites[5] = {
    'C', 'H', 'D', 'S', '\0'
};
const char colors[3] = {'B', 'R', '\0'};

int game_state = SUSPENDED;

void start(){
    if (game_state & ACTIVE){return;}
    
    game_state |= ACTIVE;

    int option = show_menu();
    while (option == -1){
        clear_stdin();
        sleep(1);
        option = show_menu();
    }
    printf("You picked option %d!\n", option);

    while(game_state & ACTIVE){

    }

    if (game_state & SUSPENDED){clean_up();}
}

void stop(){
    game_state &= ~ACTIVE;
    game_state |= SUSPENDED;
}

void clean_up(){
    printf("Cleaning up...\n");
}