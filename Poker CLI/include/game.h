#ifndef GAME_H
#define GAME_H

#define SUSPENDED (1 << 0)
#define ACTIVE (1 << 1)

extern const char cards[15];
extern const char suites[5];
extern const char colors[3];

extern int game_state;

void start();
void stop();
void clean_up();

#endif