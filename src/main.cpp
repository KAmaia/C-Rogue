#include <stdio.h>
#include <ncurses.h>

#include "../include/world.h"
#include "../include/tileloader.h"
#include "../include/worldgen.h"

//methods.
void initialize();
void handleInput(int);
void updateDisplay();
void exit();

//vars
bool running = false;
bool paused = true;
int ticks = 0;
int ROWS, COLS;
world gameWorld;
worldgen wGen;

tileLoader tl;

int main(){
	initialize();
	//gameloop
	wGen = worldgen();
	while(running == true){
		if(paused){
			//menu logic
		}
		else{
			//game logic
		}
		//handle input
		int ch = getch();
		handleInput(ch);
		ticks++;
		//update display
		updateDisplay();
		
	}
	exit();	
	return 0;
}	

void handleInput(int keyCode){
	switch(keyCode){
		case 27:
			running = false;
			break;
		default:
			//do nothing;
			break;	
	}
}		


void initialize(){
	initscr();
	getmaxyx(stdscr, ROWS, COLS);
	raw();
	nodelay(stdscr, true);
	noecho();
	keypad(stdscr, TRUE);
	running = true;
}

void updateDisplay(){
	int brrrt = ROWS - 1;
	mvprintw(1, 0, "%i, %i", ROWS, COLS);
	mvprintw(brrrt, 0,"%i", ticks); 
	refresh();
}

void exit(){
	endwin();
}
